/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	malloc()
#include <stdlib.h>
//	printf()
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	n;
	int	step;
	int	*result;

	i = 0;
	n = end - start;
	step = 1;
	if (n < 0)
		n *= -1;
	n ++;
	result = (int *) malloc(sizeof(int) * n);
	if (!result)
		return (NULL);
	if (start < end)
		step = -1;
	while (i < n)
	{
		result[i] = end;
		end += step;
		i ++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	start;
	int	end;
	int	length;
	int	i;

	if (argc != 3)
		return (1);
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	length = start - end;
	if (length < 0)
		length *= -1;
	numbers = ft_rrange(start, end);
	i = 0;
	while (i <= length)
	{
		printf("%i, ", numbers[i]);
		i ++;
	}
	printf("\n");
	free(numbers);
	return (0);
}
