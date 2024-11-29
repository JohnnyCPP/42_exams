/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	int	ft_atoi(char *string)
{
	int	result;
	int	base;

	result = 0;
	base = 10;
	while (*string != '\0')
	{
		result *= base;
		result += *string;
		result -= '0';
		string ++;
	}
	return (result);
}

static	void	print_hex(int n)
{
	const char	*digits;
	int			base;

	digits = "0123456789abcdef";
	base = 16;
	if (n >= base)
		print_hex(n / base);
	ft_putchar(digits[n % base]);
}

int	main(int argc, char **argv)
{
	int		number;
	char	*arg;

	if (argc == 2)
	{
		arg = argv[1];
		number = ft_atoi(arg);
		print_hex(number);
		write(1, "\n", 1);
	}
	return (0);
}
