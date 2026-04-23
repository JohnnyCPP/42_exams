#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_map
{
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	full;
	char	*grid;
	int		*dp;
	int		max_size;
	int		max_row;
	int		max_col;
}	t_map;

char	ft_get_cell(char *grid, int row, int col, int width);
void	ft_set_cell(char *grid, int row, int col, int width, char cell);

int		ft_get_size(int *dp, int row, int col, int width);
void	ft_set_size(int *dp, int row, int col, int width, int size);

int		ft_min_of(int a, int b, int c);
int		ft_isnumber(char c);

int		ft_parse_map(char *filename, t_map *map);
void	ft_free_map(t_map *map);

int		ft_validate_line(char *line);
int		ft_validate_printables(t_map *map);
int		ft_validate_grids(t_map *map);

void	ft_solve_bsq(t_map *map);

void	ft_print_solution(t_map *map);

#endif
