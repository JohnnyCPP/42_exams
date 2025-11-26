#include "argo.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * this function prototype needs to be declared 
 * because of the mutually recursive nature 
 * of this solution
 *
 * 1. argo_parse_json calls argo_parse_map
 * 2. argo_parse_map calls argo_parse_pair
 * 3. argo_parse_pair calls argo_parse_json
 *
 * this is a "forward declaration"
 *
 * functions can be ordered to minimize issues, 
 * but with mutual recursion it's impossible 
 * to eliminate completely
 */ 
static	int	argo_parse_json(json *dst, FILE *stream);

#define MSG_UNEXP_TOKEN "Unexpected token '%c'\n"
#define MSG_UNEXP_EOF "Unexpected end of input\n"

#define BITS_IN_BYTE 8
#define BITS_IN_8_BYTES 64

#define RET_FAILURE -1
#define RET_SUCCESS 1

#define TRUE 1
#define FALSE 0

/**
 * In Greek mythology, the Argo was the ship used 
 * by Jason and the Argonauts on their quest for 
 * the Golden Fleece
 *
 * The JSON parser is on a "quest" to navigate 
 * through complex data structures
 *
 * Just as the Argo navigated treacherous waters, 
 * argo() navigates through JSON syntax
 */

void	free_json(json j)
{
	int	i;

	if (j.type == STRING)
		free(j.string);
	else if (j.type == MAP)
	{
		i = 0;
		while (i < j.map.size)
		{
			free(j.map.data[i].key);
			free_json(j.map.data[i].value);
			i ++;
		}
		free(j.map.data);
	}
}

static	void	free_json_map(pair *pairs, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		free(pairs[i].key);
		free_json(pairs[i].value);
		i ++;
	}
	free(pairs);
}

static	int	argo_skip(FILE *stream)
{
	if (getc(stream) == EOF)
	{
		printf(MSG_UNEXP_EOF);
		return (RET_FAILURE);
	}
	return (RET_SUCCESS);
}

static	int	argo_getnext(FILE *stream)
{
	int	c;

	c = getc(stream);
	if (c == EOF)
	{
		printf(MSG_UNEXP_EOF);
		return (RET_FAILURE);
	}
	return (c);
}

static	int	argo_peek(FILE *stream)
{
	int	c;

	c = getc(stream);
	if (c == EOF)
	{
		printf(MSG_UNEXP_EOF);
		return (RET_FAILURE);
	}
	ungetc(c, stream);
	return (c);
}

static	int	argo_expect(int expected, FILE *stream)
{
	int	c;

	c = getc(stream);
	if (c == EOF)
	{
		printf(MSG_UNEXP_EOF);
		return (FALSE);
	}
	if (c != expected)
	{
		printf(MSG_UNEXP_TOKEN, c);
		return (FALSE);
	}
	return (TRUE);
}

static	int	argo_parse_integer(int *n, FILE *stream)
{
	if (fscanf(stream, "%d", n) != 1)
		return (RET_FAILURE);
	return (RET_SUCCESS);
}

static	int	argo_resize_buffer(size_t current, size_t *max, char **buffer)
{
	char	*realloc_buff;

	if (current + 1 < *max)
		return (RET_SUCCESS);
	*max *= 2;
	realloc_buff = (char *) realloc(*buffer, *max);
	if (!realloc_buff)
	{
		free(*buffer);
		*buffer = NULL;
		return (RET_FAILURE);
	}
	*buffer = realloc_buff;
	return (RET_SUCCESS);
}

static	int	argo_handle_escseq(int *c, FILE *stream)
{
	int	peek;

	if (*c != '\\')
		return (RET_SUCCESS);
	peek = argo_peek(stream);
	if (peek == RET_FAILURE)
		return (RET_FAILURE);
	if (peek == '\\')
		*c = argo_getnext(stream);
	if (peek == '\'')
		*c = argo_getnext(stream);
	if (peek == '"')
		*c = argo_getnext(stream);
	if (*c == RET_FAILURE)
		return (RET_FAILURE);
	return (RET_SUCCESS);
}

static	int	argo_parse_string(char **str, FILE *stream)
{
	int		c;
	size_t	max;
	size_t	current;
	char	*buffer;

	if (argo_skip(stream) == RET_FAILURE)
		return (RET_FAILURE);
	max = BITS_IN_8_BYTES;
	current = 0;
	buffer = (char *) malloc(max * sizeof(char));
	if (!buffer)
		return (RET_FAILURE);
	c = argo_getnext(stream);
	if (c == RET_FAILURE)
	{
		free(buffer);
		return (RET_FAILURE);
	}
	while (c != '"')
	{
		if (argo_handle_escseq(&c, stream) == RET_FAILURE)
		{
			free(buffer);
			return (RET_FAILURE);
		}
		if (argo_resize_buffer(current, &max, &buffer) == RET_FAILURE)
			return (RET_FAILURE);
		buffer[current] = c;
		c = argo_getnext(stream);
		if (c == RET_FAILURE)
		{
			free(buffer);
			return (RET_FAILURE);
		}
		current ++;
	}
	buffer[current] = '\0';
	*str = buffer;
	return (RET_SUCCESS);
}

static	int	argo_is_empty(json *dst, FILE *stream, pair **pairs)
{
	int	c;

	c = getc(stream);
	if (c == EOF)
	{
		printf(MSG_UNEXP_EOF);
		return (RET_FAILURE);
	}
	if (c == '}')
	{
		free(*pairs);
		*pairs = NULL;
		dst->map.data = NULL;
		dst->map.size = 0;
		return (TRUE);
	}
	ungetc(c, stream);
	return (FALSE);
}

static	int	argo_resize_pairs(pair **pairs, size_t current, size_t *max)
{
	pair	*realloc_pairs;

	if (current < *max)
		return (RET_SUCCESS);
	*max *= 2;
	realloc_pairs = (pair *) realloc(*pairs, *max * sizeof(pair));
	if (!realloc_pairs)
	{
		free_json_map(*pairs, current);
		return (RET_FAILURE);
	}
	*pairs = realloc_pairs;
	return (RET_SUCCESS);
}

static	int	argo_parse_pair(pair *pair, FILE *stream)
{
	if (argo_parse_string(&pair->key, stream) == RET_FAILURE)
		return (RET_FAILURE);
	if (argo_expect(':', stream) == FALSE)
		return (RET_FAILURE);
	return (argo_parse_json(&pair->value, stream));
}

static	int	argo_parse_map(json *dst, FILE *stream)
{
	size_t	max;
	size_t	current;
	pair	*pairs;
	int		c;

	if (argo_skip(stream) == RET_FAILURE)
		return (RET_FAILURE);
	max = BITS_IN_BYTE;
	current = 0;
	pairs = (pair *) malloc(max * sizeof(pair));
	if (!pairs)
		return (RET_FAILURE);
	c = argo_is_empty(dst, stream, &pairs);
	if (c == RET_FAILURE)
		return (RET_FAILURE);
	if (c == TRUE)
		return (RET_SUCCESS);
	while (TRUE)
	{
		if (argo_resize_pairs(&pairs, current, &max) == RET_FAILURE)
			return (RET_FAILURE);
		if (argo_parse_pair(&pairs[current], stream) == RET_FAILURE)
		{
			free_json_map(pairs, current);
			return (RET_FAILURE);
		}
		current ++;
		c = argo_getnext(stream);
		if (c == RET_FAILURE)
		{
			free_json_map(pairs, current);
			return (RET_FAILURE);
		}
		if (c == '}')
			break ;
		if (c != ',')
		{
			printf(MSG_UNEXP_TOKEN, c);
			free_json_map(pairs, current);
			return (RET_FAILURE);
		}
	}
	dst->map.data = pairs;
	dst->map.size = current;
	return (RET_SUCCESS);
}

static	int	argo_parse_json(json *dst, FILE *stream)
{
	int	c;

	c = argo_peek(stream);
	if (c == RET_FAILURE)
		return (RET_FAILURE);
	if (c == '-' || isdigit(c))
	{
		dst->type = INTEGER;
		return (argo_parse_integer(&dst->integer, stream));
	}
	if (c == '"')
	{
		dst->type = STRING;
		return (argo_parse_string(&dst->string, stream));
	}
	if (c == '{')
	{
		dst->type = MAP;
		return (argo_parse_map(dst, stream));
	}
	printf(MSG_UNEXP_TOKEN, c);
	return (RET_FAILURE);
}

int	argo(json *dst, FILE *stream)
{
	if (!dst || !stream)
		return (RET_FAILURE);
	return (argo_parse_json(dst, stream));
}
