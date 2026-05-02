#include "conway.h"

static void	ft_set_defaults(t_game *game)
{
	game->pen.x = 0;
	game->pen.y = 0;
	game->pen.is_down = 0;
}

static void	ft_kill_cells(t_board *board)
{
	int	cells;
	int	i;

	cells = board->width * board->height;
	i = 0;
	while (i < cells)
	{
		board->cells[i] = DEAD;
		i ++;
	}
}

int	ft_init_game(t_game *game, char **argv)
{
	game->board.width = atoi(argv[1]);
	game->board.height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);
	ft_set_defaults(game);
	if (!ft_allocate_cells(&game->board))
		return (0);
	ft_kill_cells(&game->board);
	return (1);
}
