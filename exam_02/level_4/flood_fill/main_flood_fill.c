/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flood_fill.c                                  :+:      :+:    :+:   */
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
#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin);

static	char	**make_area(char **zone, t_point size)
{
	char	**result;
	int		i;
	int		j;

	result = (char **) malloc(sizeof(char *) * size.y);
	i = 0;
	while (i < size.y)
	{
		j = 0;
		result[i] = (char *) malloc(size.x + 1);
		while (j < size.x)
		{
			result[i][j] = zone[i][j];
			j ++;
		}
		result[i][size.x] = '\0';
		i ++;
	}
	return (result);
}

static	void	assign_zone(char **zone)
{
	zone[0] = "11111111";
	zone[1] = "10001001";
	zone[2] = "10010001";
	zone[3] = "10110001";
	zone[4] = "11100001";
}

static	void	print_zone(char **zone, t_point size)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		printf("%s\n", zone[i]);
		i ++;
	}
}

static	void	free_zone(char **zone, t_point size)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		free(zone[i]);
		i ++;
	}
	free(zone);
}

int	main(void)
{
	t_point	size;
	t_point	start;
	char	**zone;
	char	**result;
	int		i;

	size = (t_point){8, 5};
	start = (t_point){7, 4};
	zone = (char **) malloc(size.y * sizeof(char *));
	if (!zone)
		return (1);
	assign_zone(zone);
	result = make_area(zone, size);
	free(zone);
	print_zone(result, size);
	printf("%s\n", "========");
	flood_fill(result, size, start);
	print_zone(result, size);
	printf("%s\n", "========");
	free_zone(result, size);
	return (0);
}
