#include "bsq.h"

static void	ft_update_max(t_map *map, int row, int col)
{
	int	size;

	size = ft_get_size(map, row, col);
	if (size > map->max_size)
	{
		map->max_size = size;
		map->max_row = row;
		map->max_col = col;
	}
}

static void	ft_find_bsq(t_map *map)
{
	int		row;
	int		col;
	int		min_size;
	int		above;
	int		diagonal;
	int		left;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (ft_get_cell(map, row, col) == map->obstacle)
				min_size = 0;
			else if (row == 0 || col == 0)
				min_size = 1;
			else
			{
				above = ft_get_size(map, row - 1, col);
				diagonal = ft_get_size(map, row - 1, col - 1);
				left = ft_get_size(map, row, col - 1);
				min_size = ft_min_of(above, left, diagonal) + 1;
			}
			ft_set_size(map, row, col, min_size);
			ft_update_max(map, row, col);
			col ++;
		}
		row ++;
	}
}

static void	ft_mark_bsq(t_map *map)
{
	int	start_row;
	int	start_col;
	int	row;
	int	col;

	start_row = map->max_row - map->max_size + 1;
	start_col = map->max_col - map->max_size + 1;
	row = 0;
	while (row < map->max_size)
	{
		col = 0;
		while (col < map->max_size)
		{
			ft_set_cell(map, start_row + row, start_col + col, map->full);
			col ++;
		}
		row ++;
	}
}

void	ft_solve_bsq(t_map *map)
{
	ft_compute_sizes(map);
	ft_mark_bsq(map);
}
