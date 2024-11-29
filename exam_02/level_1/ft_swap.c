/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	printf()
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	first_number;

	first_number = *a;
	*a = *b;
	*b = first_number;
}

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 10;
	ft_swap(&a, &b);
	printf("Value a:%i\nValue b:%i\n", a, b);
	return (0);
}
