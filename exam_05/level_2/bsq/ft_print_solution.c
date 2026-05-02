#include "bsq.h"

void	ft_print_solution(t_map *map)
{
	char	cell;
	int		row;
	int		col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			cell = ft_get_cell(map, row, col);
			fprintf(stdout, "%c", cell);
			col ++;
		}
		fprintf(stdout, "\n");
		row ++;
	}
}
