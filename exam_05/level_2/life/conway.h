#ifndef CONWAY_H
# define CONWAY_H

// conway's game of life: cellular automaton
//
//
// Hi, reader. I have to write this here because the subject does not explain 
// what a "game of life" is. Thanks for reading.
//
//
// The Game of Life is a zero-player game where cells on a grid live, die, or 
// reproduce based on their neighbors.
//
// The neighbors of a cell are the 8 surrounding cells: horizontal, 
// vertical and diagonal.
//
// The initial pattern constitutes the "seed" of the system.
//
// The first "generation" is created by applying the rules explained below 
// simultaneously to every cell in the "seed", live or dead.
//
// Births and deaths occur simultaneously, and the discrete moment at which 
// this happens can be called a "tick".
//
//
// Each iteration (generation) follows these rules:
//
// 1. any live cell with fewer than 2 live neighbors dies by underpopulation
//
// 2. any live cell with 2 or 3 live neighbors lives to the next generation
//
// 3. any live cell with more than 3 live neighbors dies for overpopulation
//
// 4. any dead cell with 3 live neighbors becomes alive by reproduction
//
//
// The "iterations" parameter of the program refers to the number 
// of GENERATIONS (and the amount of "ticks") of the game.

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# define ALIVE 'O'
# define DEAD ' '

typedef struct s_pen
{
	int	x;
	int	y;
	int	is_down;
}	t_pen;

typedef struct s_board
{
	int		width;
	int		height;
	char	*cells;
}	t_board;

typedef struct s_game
{
	int		iterations;
	t_pen	pen;
	t_board	board;
}	t_game;

void	ft_set_cell(t_board *board, int x, int y, char cell);
char	ft_get_cell(t_board *board, int x, int y);

int		ft_allocate_cells(t_board *board);
void	ft_print_cells(t_board *board);
void	ft_free_cells(t_board *board);

int		ft_init_game(t_game *game, char **argv);

void	ft_read_drawing(t_game *game);

int		ft_simulate_generation(t_game *game);

#endif
