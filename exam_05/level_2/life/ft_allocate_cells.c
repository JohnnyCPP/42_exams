#include "conway.h"

int	ft_allocate_cells(t_board *board)
{
	int	cells;

	cells = board->width * board->height;
	board->cells = (char *) calloc(cells + 1, sizeof(char));
	if (!board->cells)
		return (-1);
	return (0);
}
