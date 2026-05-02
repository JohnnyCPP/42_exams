#include "bsq.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;
	int		is_parsed;

	if (argc == 1)
	{
		map = (t_map){0};
		is_parsed = ft_parse_map(NULL, &map);
		if (is_parsed && map.grid && map.dp)
		{
			ft_solve_bsq(&map);
			ft_print_solution(&map);
			ft_free_map(&map);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map = (t_map){0};
			is_parsed = ft_parse_map(argv[i], &map);
			if (is_parsed && map.grid && map.dp)
			{
				ft_solve_bsq(&map);
				ft_print_solution(&map);
				ft_free_map(&map);
			}
			if (i + 1 < argc)
				fprintf(stdout, "\n");
			i ++;
		}
	}
	return (0);
}
