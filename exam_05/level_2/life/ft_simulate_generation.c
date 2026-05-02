#include "conway.h"

static int	ft_count_neighbors(t_board *board, int x, int y)
{
	char	cell;
	int		neighbors;
	int		delta_x;
	int		delta_y;

	neighbors = 0;
	delta_y = -1;
	while (delta_y <= 1)
	{
		delta_x = -1;
		while (delta_x <= 1)
		{
			if (delta_x == 0 && delta_y == 0)
			{
				delta_x ++;
				continue ;
			}
			cell = ft_get_cell(board, x + delta_x, y + delta_y);
			if (cell == ALIVE)
				neighbors ++;
			delta_x ++;
		}
		delta_y ++;
	}
	return (neighbors);
}

static char	ft_next_cell_state(t_board *board, int x, int y)
{
	char	cell;
	int		neighbors;

	cell = ft_get_cell(board, x, y);
	neighbors = ft_count_neighbors(board, x, y);
	if (cell == ALIVE)
	{
		if (neighbors == 2 || neighbors == 3)
			return (ALIVE);
		return (DEAD);
	}
	else
	{
		if (neighbors == 3)
			return (ALIVE);
		return (DEAD);
	}
}

static void	ft_compute_generation(t_board *src, t_board *dst)
{
	int		x;
	int		y;
	char	next_cell;

	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			next_cell = ft_next_cell_state(src, x, y);
			ft_set_cell(dst, x, y, next_cell);
			x ++;
		}
		y ++;
	}
}

int	ft_simulate_generation(t_game *game)
{
	t_board	next_board;

	next_board.width = game->board.width;
	next_board.height = game->board.height;
	if (!ft_allocate_cells(&next_board))
		return (0);
	ft_compute_generation(&game->board, &next_board);
	ft_free_cells(&game->board);
	game->board.cells = next_board.cells;
	return (1);
}
