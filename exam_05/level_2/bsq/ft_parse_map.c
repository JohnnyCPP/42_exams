#include "bsq.h"

static int	ft_parse_header(char *line, t_map *map)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (ft_isnumber(line[i]))
	{
		height = height * 10 + (line[i] - '0');
		i ++;
	}
	map->height = height;
	while (line[i] == ' ')
		i ++;
	map->empty = line[i ++];
	while (line[i] == ' ')
		i ++;
	map->obstacle = line[i ++];
	while (line[i] == ' ')
		i ++;
	map->full = line[i ++];
	if (map->height <= 0)
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full 
			|| map->obstacle == map->full)
		return (0);
	return (1);
}

static int	ft_get_width(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i ++;
	return (i);
}

static int	ft_alloc_memory(t_map *map)
{
	map->grid = (char *) calloc(map->height * map->width + 1, sizeof(char));
	if (!map->grid)
		return (0);
	map->dp = (int *) calloc(map->height * map->width + 1, sizeof(int));
	if (!map->dp)
	{
		free(map->grid);
		map->grid = NULL;
		return (0);
	}
	return (1);
}

static int	ft_store_line(char *line, int row, t_map *map)
{
	int	width;
	int	col;

	if (!ft_validate_line(line))
		return (0);
	width = ft_get_width(line);
	if (width != map->width)
		return (0);
	col = 0;
	while (col < width)
	{
		if (line[col] != map->empty && line[col] != map->obstacle)
			return (0);
		ft_set_cell(map->grid, row, col, map->width, line[col]);
		col ++;
	}
	return (1);
}

int	ft_parse_map(char *filename, t_map *map)
{
	int		header_read;
	FILE	*file;
	char	*line;
	size_t	size;
	int		row;

	header_read = 0;
	file = NULL;
	line = NULL;
	size = 0;
	row = 0;
	if (filename)
		file = fopen(filename, "r");
	else
		file = stdin;
	if (!file)
		return (0);
	while (getline(&line, &size, file) != -1)
	{
		if (!header_read)
		{
			if (!ft_parse_header(line, map))
				goto error;
			header_read = 1;
		}
		else if (row == 0)
		{
			map->width = ft_get_width(line);
			if (map->width <= 0)
				goto error;
			if (!ft_alloc_memory(map))
				goto error;
			if (!ft_store_line(line, row, map))
				goto error;
			row ++;
		}
		else
		{
			if (row == map->height && line[0] == '\n')
				break;
			if (!ft_store_line(line, row, map))
				goto error;
			row ++;
		}
	}
	if (row != map->height)
		goto error;
	if (!ft_validate_printables(map) || !ft_validate_grids(map))
		goto error;
	free(line);
	if (filename && file)
		fclose(file);
	return (1);
error:
	free(line);
	if (filename && file)
		fclose(file);
	ft_free_map(map);
	fprintf(stderr, "map error\n");
	return (0);
}
