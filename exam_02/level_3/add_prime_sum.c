/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	int	ft_atoi(char *string)
{
	int	result;
	int	digit;

	result = 0;
	while (*string != '\0')
	{
		digit = (*string) - '0';
		result *= 10;
		result += digit;
		string ++;
	}
	return (result);
}

static	int	ft_isprime(int n)
{
	int	i;

	if (n <= 1)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

static	void	ft_putnbr(int n)
{
	char	digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		number;
	int		result;

	if (argc == 2)
	{
		arg = argv[1];
		number = ft_atoi(arg);
		result = 0;
		while (number > 0)
		{
			if (ft_isprime(number))
				result += number;
			number --;
		}
		ft_putnbr(result);
	}
	else
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
