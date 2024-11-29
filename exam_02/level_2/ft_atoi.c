/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

//	printf()
#include <stdio.h>

static	int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static	int	ft_issign(char c)
{
	if ('+' == c || c == '-')
		return (1);
	return (0);
}

static	int	ft_isspace(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str ++;
	if (*str == '-')
		sign = -1;
	if (ft_issign(*str))
		str ++;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		str ++;
	}
	return (sign * result);
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		number;

	if (argc == 2)
	{
		arg = argv[1];
		number = ft_atoi(arg);
		printf("Number:%d\n", number);
	}
	return (0);
}
