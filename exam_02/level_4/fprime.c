/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
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

int	main(int argc, char **argv)
{
	int	i;
	int	current;

	if (argc != 2)
		return (1);
	i = 2;
	current = atoi(argv[1]);
	if (current == 1)
		printf("%i", current);
	while (current >= i)
	{
		if (current % i == 0)
		{
			printf("%i", i);
			if (current == i)
				break ;
			printf("*");
			current /= i;
			i = 1;
		}
		i ++;
	}
	printf("\n");
	return (0);
}
