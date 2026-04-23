#include "bsq.h"

static void	ft_update_max(t_map *map, int row, int col)
{
	int	size;

	size = ft_get_size(map->dp, row, col, map->width);
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
	int		size;
	char	cell;
	int		above;
	int		left;
	int		diagonal;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			cell = ft_get_cell(map->grid, row, col, map->width);
			if (cell == map->obstacle)
				size = 0;
			else if (row == 0 || col == 0)
				size = 1;
			else
			{
				above = ft_get_size(map->dp, row - 1, col, map->width);
				left = ft_get_size(map->dp, row, col - 1, map->width);
				diagonal = ft_get_size(map->dp, row - 1, col - 1, map->width);
				size = 1 + ft_min_of(above, left, diagonal);
			}
			ft_set_size(map->dp, row, col, map->width, size);
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
			ft_set_cell(map->grid, start_row + row, start_col + col,
					map->width, map->full);
			col ++;
		}
		row ++;
	}
}

void	ft_solve_bsq(t_map *map)
{
	map->max_size = 0;
	map->max_row = 0;
	map->max_col = 0;
	ft_find_bsq(map);
	if (map->max_size > 0)
		ft_mark_bsq(map);
}
