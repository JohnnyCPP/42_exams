#include "conway.h"

static int	ft_count_neighbors(t_board *board, int x, int y)
{
	int	count;
	int	delta_x;
	int	delta_y;

	count = 0;
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
			if (ft_get_cell(board, x + delta_x, y + delta_y) == ALIVE)
				count ++;
			delta_x ++;
		}
		delta_y ++;
	}
	return (count);
}

static char	ft_next_cell_state(t_board *board, int x, int y)
{
	int		neighbors;
	char	current;

	current = ft_get_cell(board, x, y);
	neighbors = ft_count_neighbors(board, x, y);
	if (current == ALIVE)
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

static void	ft_compute_generation(t_board *current, t_board *next)
{
	char	next_cell;
	int		x;
	int		y;

	y = 0;
	while (y < current->height)
	{
		x = 0;
		while (x < current->width)
		{
			next_cell = ft_next_cell_state(current, x, y);
			ft_set_cell(next, x, y, next_cell);
			x ++;
		}
		y ++;
	}
}

static int	ft_allocate_next_cells(t_board *src, t_board *dst)
{
	int	cells;

	cells = src->width * src->height;
	dst->width = src->width;
	dst->height = src->height;
	dst->cells = (char *) calloc(cells + 1, sizeof(char));
	if (!dst->cells)
		return (-1);
	return (0);
}

int	ft_simulate_generation(t_game *game)
{
	t_board	next_board;

	if (ft_allocate_next_cells(&game->board, &next_board) == -1)
		return (-1);
	ft_compute_generation(&game->board, &next_board);
	ft_free_cells(&game->board);
	game->board.cells = next_board.cells;
	return (0);
}
