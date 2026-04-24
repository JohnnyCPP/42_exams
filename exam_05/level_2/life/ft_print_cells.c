#include "conway.h"

static void	ft_print_row(t_board *board, int y)
{
	int	x;

	x = 0;
	while (x < board->width)
	{
		putchar(ft_get_cell(board, x, y));
		x ++;
	}
}

void	ft_print_cells(t_board *board)
{
	int	y;

	y = 0;
	while (y < board->height)
	{
		ft_print_row(board, y);
		putchar('\n');
		y ++;
	}
}
