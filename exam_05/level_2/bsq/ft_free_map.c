#include "bsq.h"

void	ft_free_map(t_map *map)
{
	if (map->grid)
	{
		free(map->grid);
		map->grid = NULL;
	}
	if (map->dp)
	{
		free(map->dp);
		map->dp = NULL;
	}
}
