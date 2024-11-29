/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
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

void	print_bits(unsigned char octet)
{
	char			i;
	unsigned char	bitwise;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bitwise = octet >> i & 1;
		bit = bitwise + '0';
		ft_putchar(bit);
		i --;
	}
	ft_putchar('\n');
}

int	main(void)
{
	unsigned char	octet;

	octet = 0b00100010;
	print_bits(octet);
	return (0);
}
