/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	malloc() & free()
#include <stdlib.h>
//	write()
#include <unistd.h>

char	*ft_strcpy(char *destination, char *source)
{
	int	iterator;

	iterator = 0;
	while (source[iterator] != '\0')
	{
		destination[iterator] = source[iterator];
		iterator ++;
	}
	destination[iterator] = '\0';
	return (destination);
}

static	int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length ++;
	return (length);
}

static	void	ft_putendl(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index ++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	*source;
	char	*destination;
	int		length;

	if (argc != 2)
		return (0);
	source = argv[1];
	length = ft_strlen(source);
	destination = (char *) malloc(length * sizeof(char) + 1);
	ft_strcpy(destination, source);
	ft_putendl(destination);
	free(destination);
	return (0);
}
