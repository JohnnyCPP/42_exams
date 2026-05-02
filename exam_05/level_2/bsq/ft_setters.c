#include "bsq.h"

void	ft_set_cell(t_map *map, int row, int col, char cell)
{
	int	index;

	index = row * map->width + col;
	map->grid[index] = cell;
}

char	ft_get_cell(t_map *map, int row, int col)
{
	int	index;

	index = row * map->width + col;
	return (map->grid[index]);
}

void	ft_set_size(t_map *map, int row, int col, int size)
{
	int	index;

	index = row * map->width + col;
	map->dp[index] = size;
}

int	ft_get_size(t_map *map, int row, int col)
{
	int	index;

	index = row * map->width + col;
	return (map->dp[index]);
}
