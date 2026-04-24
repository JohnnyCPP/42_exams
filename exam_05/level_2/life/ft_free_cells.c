#include "conway.h"

void	ft_free_cells(t_board *board)
{
	if (board->cells)
	{
		free(board->cells);
		board->cells = NULL;
	}
}
