#include "conway.h"

static int	ft_validate_args(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0)
		return (0);
	if (atoi(argv[3]) < 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (!ft_validate_args(argc, argv))
		return (1);
	if (!ft_init_game(&game, argv))
		return (1);
	ft_read_drawing(&game);
	i = 0;
	while (i < game.iterations)
	{
		if (!ft_simulate_generation(&game))
		{
			ft_free_cells(&game.board);
			return (1);
		}
		i ++;
	}
	ft_print_cells(&game.board);
	ft_free_cells(&game.board);
	return (0);
}
