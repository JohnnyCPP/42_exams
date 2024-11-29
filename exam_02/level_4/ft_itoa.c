/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	malloc()
#include <stdlib.h>

static	int	digit_length(int number)
{
	int	i;
	int	base;

	if (!number)
		return (1);
	i = 0;
	base = 10;
	while (number)
	{
		number /= base;
		i ++;
	}
	return (i);
}

static	int	absolute_of(int number)
{
	int	inverse;

	inverse = -number;
	if (number < 0)
		return (inverse);
	return (number);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		digit_length;
	int		digit;
	int		base;
	int		i;

	digit_length = digit_length(nbr);
	i = 0;
	base = 10;
	if (nbr < 0)
		i ++;
	digit_length += i;
	result = (char *) malloc(sizeof(char) * digit_length + 1);
	if (!result)
		return (NULL);
	result[0] = '-';
	result[digit_length] = '\0';
	while (digit_length > i)
	{
		digit_length --;
		digit = absolute_of(nbr % base) + '0';
		result[digit_length] = digit;
		nbr /= base;
	}
	return (result);
}
