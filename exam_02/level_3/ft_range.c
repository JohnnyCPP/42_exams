/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	abs()
#include <stdlib.h>
//	printf()
#include <stdio.h>

static	void	ft_backward(int *result, int *start, int *i)
{
	result[*i] = *start;
	(*start)--;
	(*i)++;
}

static	void	ft_forward(int *result, int *start, int *i)
{
	result[*i] = *start;
	(*start)++;
	(*i)++;
}

int	*ft_range(int start, int end)
{
	int	i;
	int	length;
	int	*result;

	i = 0;
	length = abs(end - start) + 1;
	result = (int *) malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	while (i < length)
	{
		if (start < end)
			ft_forward(result, &start, &i);
		else
			ft_backward(result, &start, &i);
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
	numbers = ft_range(start, end);
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
