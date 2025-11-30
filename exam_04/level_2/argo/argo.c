#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct	pair {
	char	*key;
	json	value;
}	pair;

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

static	void	argo_free_pairs(pair *pairs, size_t length);

#define MSG_UNEXP_TOKEN "Unexpected token '%c'\n"
#define MSG_UNEXP_EOF "Unexpected end of input\n"

#define BITS_IN_BYTE 8

#define RET_FAILURE -1
#define RET_SUCCESS 1

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

void	argo_free_json(json *j)
{
	pair	*pairs;
	size_t	size;

	if (j->type == STRING)
		free(j->string);
	else if (j->type == MAP)
	{
		pairs = j->map.data;
		size = j->map.size;
		argo_free_pairs(pairs, size);
	}
}

static	void	argo_free_pairs(pair *pairs, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(pairs[i].key);
		argo_free_json(&pairs[i].value);
		i ++;
	}
	free(pairs);
}

static	int	argo_get_next(FILE *stream)
{
	int	c;

	c = getc(stream);
	if (c == EOF)
		return (EOF);
	return (c);
}

static	int	argo_peek(FILE *stream)
{
	int	c;

	c = getc(stream);
	if (c == EOF)
		return (EOF);
	if (ungetc(c, stream) == EOF)
		return (EOF);
	return (c);
}

static	void	argo_print_unexpected(int c)
{
	if (c == '\0')
		printf(MSG_UNEXP_EOF);
	else
		printf(MSG_UNEXP_TOKEN, c);
}

static	int	argo_parse_integer(int *n, FILE *stream)
{
	if (fscanf(stream, "%d", n) != 1)
		return (RET_FAILURE);
	return (RET_SUCCESS);
}

static	int	argo_resize_buffer(char **buffer, size_t *max, size_t current)
{
	char	*realloc_buffer;

	if (current + 1 < *max)
		return (RET_SUCCESS);
	*max *= 2;
	realloc_buffer = (char *) realloc(*buffer, *max);
	if (!realloc_buffer)
		return (RET_FAILURE);
	*buffer = realloc_buffer;
	return (RET_SUCCESS);
}

static	int	argo_handle_escseq(int *c, FILE *stream)
{
	int	peek;

	if (*c != '\\')
		return (RET_SUCCESS);
	peek = argo_peek(stream);
	if (peek == '\\')
		*c = argo_get_next(stream);
	else if (peek == '\'')
		*c = argo_get_next(stream);
	else if (peek == '"')
		*c = argo_get_next(stream);
	if (*c == EOF)
		return (RET_FAILURE);
	return (RET_SUCCESS);
}

static	int	argo_parse_string(char **str, FILE *stream)
{
	int		c;
	size_t	max;
	size_t	current;
	char	*buffer;

	if (argo_peek(stream) == '"')
		argo_get_next(stream);
	max = BITS_IN_BYTE;
	current = 0;
	buffer = (char *) malloc(max * sizeof(char));
	if (!buffer)
		return (RET_FAILURE);
	c = argo_get_next(stream);
	while (c != '"')
	{
		if (c == EOF)
		{
			free(buffer);
			return (RET_FAILURE);
		}
		if (argo_handle_escseq(&c, stream) == RET_FAILURE)
		{
			free(buffer);
			return (RET_FAILURE);
		}
		if (argo_resize_buffer(&buffer, &max, current) == RET_FAILURE)
		{
			free(buffer);
			return (RET_FAILURE);
		}
		buffer[current ++] = c;
		c = argo_get_next(stream);
	}
	buffer[current] = '\0';
	*str = buffer;
	return (RET_SUCCESS);
}

static	int	argo_resize_pairs(pair **pairs, size_t *max, size_t current)
{
	pair	*realloc_pairs;

	if (current < *max)
		return (RET_SUCCESS);
	*max *= 2;
	realloc_pairs = (pair *) realloc(*pairs, *max * sizeof(pair));
	if (!realloc_pairs)
		return (RET_FAILURE);
	*pairs = realloc_pairs;
	return (RET_SUCCESS);
}

static	int	argo_parse_pair(pair *pair, FILE *stream)
{
	int	c;

	if (argo_parse_string(&pair->key, stream) == RET_FAILURE)
		return (RET_FAILURE);
	c = argo_get_next(stream);
	if (c == EOF || c != ':')
	{
		argo_print_unexpected(c);
		return (RET_FAILURE);
	}
	return (argo_parse_json(&pair->value, stream));
}

static	int	argo_parse_map(json *dst, FILE *stream)
{
	size_t	max;
	size_t	current;
	pair	*pairs;
	int		c;

	if (argo_peek(stream) == '{')
		argo_get_next(stream);
	max = BITS_IN_BYTE;
	current = 0;
	pairs = (pair *) malloc(max * sizeof(pair));
	if (!pairs)
		return (RET_FAILURE);
	c = argo_get_next(stream);
	while (c != '}')
	{
		if (c == EOF)
		{
			argo_free_pairs(pairs, current);
			return (RET_FAILURE);
		}
		if (argo_resize_pairs(&pairs, &max, current) == RET_FAILURE)
		{
			argo_free_pairs(pairs, current);
			return (RET_FAILURE);
		}
		if (argo_parse_pair(&pairs[current], stream) == RET_FAILURE)
		{
			argo_free_pairs(pairs, current);
			return (RET_FAILURE);
		}
		current ++;
		c = argo_get_next(stream);
		if (c != ',' && c != '}')
		{
			argo_free_pairs(pairs, current);
			argo_print_unexpected(c);
			return (RET_FAILURE);
		}
		if (c == ',')
			c = argo_get_next(stream);
	}
	dst->map.data = pairs;
	dst->map.size = current;
	return (RET_SUCCESS);
}

static	int	argo_parse_json(json *dst, FILE *stream)
{
	int	c;

	c = argo_peek(stream);
	if (c == EOF)
	{
		argo_print_unexpected(c);
		return (EOF);
	}
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
	argo_print_unexpected(c);
	return (RET_FAILURE);
}

int	argo(json *dst, FILE *stream)
{
	if (!dst || !stream)
		return (RET_FAILURE);
	return (argo_parse_json(dst, stream));
}
