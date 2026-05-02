#include "bsq.h"

int	ft_validate_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i ++;
	return (line[i] == '\n');
}

static int	ft_isprintable(char c)
{
	return (' ' <= c && c <= '~');
}

int	ft_validate_printables(t_map *map)
{
	if (!ft_isprintable(map->empty))
		return (0);
	if (!ft_isprintable(map->obstacle))
		return (0);
	if (!ft_isprintable(map->full))
		return (0);
	return (1);
}

int	ft_validate_grid(t_map *map)
{
	int	found_obstacle;
	int	found_empty;
	int	map_size;
	int	i;

	found_obstacle = 0;
	found_empty = 0;
	map_size = map->height * map->width;
	i = 0;
	while (i < map_size)
	{
		if (!found_obstacle && map->grid[i] == map->obstacle)
			found_obstacle = 1;
		if (!found_empty && map->grid[i] == map->empty)
			found_empty = 1;
		if (found_obstacle && found_empty)
			return (1);
		i ++;
	}
	return (0);
}
