#include "conway.h"

void	ft_set_cell(t_board *board, int x, int y, char cell)
{
	int	index;

	if (x < 0 || x >= board->width || y < 0 || y >= board->height)
		return ;
	index = y * board->width + x;
	board->cells[index] = cell;
}

char	ft_get_cell(t_board *board, int x, int y)
{
	int	index;

	if (x < 0 || x >= board->width || y < 0 || y >= board->height)
		return (DEAD);
	index = y * board->width + x;
	return (board->cells[index]);
}
