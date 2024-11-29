/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	char	to_lower(const char c)
{
	char	aux;
	int		offset;

	aux = (char) c;
	offset = 'a' - 'A';
	if ('A' <= aux && aux <= 'Z')
		aux += offset;
	return (aux);
}

static	int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static	int	ft_ishexchar(char c)
{
	if ('a' <= c && c <= 'f')
		return (1);
	return (0);
}

static	int	get_digit(const char c, int base)
{
	char	aux;
	int		max_digit;

	aux = (char) c;
	if (base <= 10)
		max_digit = base - 1 + '0';
	else
		max_digit = base - 10 - 1 + 'a';
	if (ft_isdigit(aux) && aux <= max_digit)
		return (aux - '0');
	else if (ft_ishexchar(aux) && aux <= max_digit)
		return (10 + aux - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char	lowercase;
	int		result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	if (str == NULL || str_base < 2 || str_base > 16)
		return (0);
	if (*str == '-')
	{
		sign = -1;
		str ++;
	}
	while (*str != '\0')
	{
		lowercase = to_lower(*str);
		digit = get_digit(lowercase, str_base);
		if (digit == -1)
			break ;
		result *= str_base;
		result += digit;
		str ++;
	}
	return (result * sign);
}
