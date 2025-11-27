#ifndef VBC_H
# define VBC_H

# include <stdio.h>
# include <ctype.h>

typedef struct	s_parser
{
	const	char	*input;
	int				pos;
	int				error;
}	t_parser;

#endif
