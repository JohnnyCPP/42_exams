/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	atoi()
#include <stdlib.h>
//	printf()
#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	int	subtraction;
	int	bitwise;

	if (n == 0)
		return (0);
	subtraction = n - 1;
	bitwise = n & subtraction;
	if (bitwise == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc == 2)
	{
		number = atoi(argv[1]);
		if (is_power_of_2(number))
			printf("Number %i is power of two.\n", number);
		else
			printf("Number %i is not power of two.\n", number);
	}
	return (0);
}
