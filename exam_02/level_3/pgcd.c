/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	atoi()
#include <stdlib.h>
//	printf
#include <stdio.h>

static	void	ft_compute(int *number_1, int *number_2)
{
	while (*number_1 != *number_2)
	{
		if (*number_1 > *number_2)
			*number_1 -= *number_2;
		else
			*number_2 -= *number_1;
	}
}

int	main(int argc, const char **argv)
{
	int			number_1;
	int			number_2;
	const char	*arg_1;
	const char	*arg_2;

	if (argc == 3)
	{
		arg_1 = argv[1];
		arg_2 = argv[2];
		number_1 = atoi(arg_1);
		number_2 = atoi(arg_2);
		if (number_1 > 0 && number_2 > 0)
		{
			ft_compute(&number_1, &number_2);
			printf("%i", number_1);
		}
		printf("\n");
	}
	return (0);
}
