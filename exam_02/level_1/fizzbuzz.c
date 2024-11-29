/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	void	ft_write_number(int number)
{
	char	*numbers;

	numbers = "0123456789";
	if (number > 9)
		ft_write_number(number / 10);
	write(1, &numbers[number % 10], 1);
}

int	main(void)
{
	int	iterator;

	iterator = 1;
	while (iterator <= 100)
	{
		if (iterator % 15 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (iterator % 3 == 0)
			write(1, "fizz\n", 5);
		else if (iterator % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_write_number(iterator);
			write(1, "\n", 1);
		}
		iterator ++;
	}
	return (0);
}
