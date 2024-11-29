/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	int	ft_isspace(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

static	int	ft_atoi(char *string)
{
	int	result;
	int	base;

	result = 0;
	base = 10;
	while (ft_isspace(*string))
		string ++;
	if (*string == '+')
		string ++;
	while ('0' <= *string && *string <= '9')
	{
		result *= base;
		result += *string;
		result -= '0';
		string ++;
	}
	return (result);
}

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	void	ft_putnbr(int number)
{
	int		base;
	char	digit;

	base = 10;
	if (number / base > 0)
		ft_putnbr(number / base);
	digit = number % base;
	digit += '0';
	ft_putchar(digit);
}

int	main(int argc, char **argv)
{
	int	i;
	int	number;
	int	multiplication;

	if (argc != 2)
		return (0);
	i = 1;
	number = ft_atoi(argv[1]);
	while (i <= 9 && number <= 238609183)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(number);
		write(1, " = ", 3);
		multiplication = i * number;
		ft_putnbr(multiplication);
		write(1, "\n", 1);
		i ++;
	}
	return (0);
}
