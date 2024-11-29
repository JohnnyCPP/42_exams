/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	malloc()
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*result;

	i = 0;
	length = 0;
	while (src[length])
		length++;
	result = malloc(sizeof(char) * length + 1);
	if (result != NULL)
	{
		while (src[i])
		{
			result[i] = src[i];
			i ++;
		}
		result[i] = '\0';
	}
	return (result);
}
