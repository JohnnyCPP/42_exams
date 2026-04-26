NAME		= bsq

CC			= cc
SANITIZE	= -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -g3

SRC			= ft_free_map.c \
			  ft_isnumber.c \
			  ft_min_of.c \
			  ft_parse_map.c \
			  ft_print_solution.c \
			  ft_setters.c \
			  ft_solve_bsq.c \
			  ft_validation.c \
			  main.c


all: ${NAME}


${NAME}:
	${CC} ${CFLAGS} ${SANITIZE} ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


fclean: clean


re: clean all


.PHONY: all clean fclean re
