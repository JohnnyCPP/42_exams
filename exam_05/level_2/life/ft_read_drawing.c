#include "conway.h"

static int	ft_isdirection(char c)
{
	return (c == 'w' || c == 'a' || c == 's' || c == 'd');
}

static void	ft_toggle_pen(t_game *game)
{
	game->pen.is_down = !game->pen.is_down;
	if (game->pen.is_down)
		ft_set_cell(&game->board, game->pen.x, game->pen.y, ALIVE);
}

static void	ft_move_pen(t_game *game, char direction)
{
	if (direction == 'w' && game->pen.y > 0)
		game->pen.y --;
	else if (direction == 's' && game->pen.y + 1 < game->board.height)
		game->pen.y ++;
	else if (direction == 'a' && game->pen.x > 0)
		game->pen.x --;
	else if (direction == 'd' && game->pen.x + 1 < game->board.width)
		game->pen.x ++;
	if (game->pen.is_down)
		ft_set_cell(&game->board, game->pen.x, game->pen.y, ALIVE);
}

void	ft_read_drawing(t_game *game)
{
	char	buffer;

	while (read(0, &buffer, 1) == 1)
	{
		if (buffer == 'x')
			ft_toggle_pen(game);
		else if (ft_isdirection(buffer))
			ft_move_pen(game, buffer);
	}
}
