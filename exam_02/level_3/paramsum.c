/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	void	ft_putnbr(int number)
{
	char	digit;

	if (number >= 10)
		ft_putnbr(number / 10);
	digit = number % 10;
	digit += '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	(void) argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
