/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	malloc()
#include <stdlib.h>
//	NULL
#include <stddef.h>

static	char	*ft_strncpy(char *destination, char *source, int length)
{
	int	i;

	if (!destination || !source)
		return (NULL);
	i = 0;
	while (source[i] && i < length)
	{
		destination[i] = source[i];
		i ++;
	}
	destination[i] = '\0';
	return (destination);
}

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static	int	ft_count_words(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_isspace(str[i]))
			i ++;
		if (str[i] != '\0')
			result ++;
		while (str[i] != '\0' && !ft_isspace(str[i]))
			i ++;
	}
	return (result);
}

static	int	ft_split_words(char *str, char **result, int i, int word)
{
	int	start;

	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_isspace(str[i]))
			i ++;
		start = i;
		while (str[i] != '\0' && !ft_isspace(str[i]))
			i ++;
		if (i > start)
		{
			result[word] = (char *) malloc(sizeof(char) * (i - start + 1));
			if (!result[word])
			{
				while (word > 0)
					free(result[--word]);
				return (0);
			}
			ft_strncpy(result[word], str + start, i - start);
			word ++;
		}
	}
	result[word] = NULL;
	return (1);
}

char	**ft_split(char *str)
{
	char	**result;
	int		wcount;
	int		is_allocated;

	if (!str)
		return (NULL);
	wcount = ft_count_words(str);
	result = (char **) malloc(sizeof(char *) * (wcount + 1));
	if (!result)
		return (NULL);
	is_allocated = ft_split_words(str, result, 0, 0);
	if (!is_allocated)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
