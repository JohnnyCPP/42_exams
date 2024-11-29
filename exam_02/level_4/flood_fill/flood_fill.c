/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static	int	is_out_of_bounds(t_point current, t_point size, char **tab, char c)
{
	if (current.x < 0 || current.x >= size.x)
		return (1);
	if (current.y < 0 || current.y >= size.y)
		return (1);
	if (tab[current.y][current.x] != c)
		return (1);
	return (0);
}

static	void	fill(char **tab, t_point size, t_point current, char to_fill)
{
	t_point	up;
	t_point	down;
	t_point	left;
	t_point	right;

	if (is_out_of_bounds(current, size, tab, to_fill))
		return ;
	tab[current.y][current.x] = 'F';
	up = (t_point){current.x, current.y - 1};
	down = (t_point){current.x, current.y + 1};
	left = (t_point){current.x - 1, current.y};
	right = (t_point){current.x + 1, current.y};
	fill(tab, size, up, to_fill);
	fill(tab, size, down, to_fill);
	fill(tab, size, left, to_fill);
	fill(tab, size, right, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
