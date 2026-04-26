NAME		= life

CC			= cc
SANITIZE	= -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -g3

SRC			= ft_allocate_cells.c \
			  ft_init_game.c \
			  ft_read_drawing.c \
			  ft_simulate_generation.c \
			  ft_free_cells.c \
			  ft_print_cells.c \
			  ft_setters.c \
			  main.c


all: ${NAME}


${NAME}:
	${CC} ${CFLAGS} ${SANITIZE} ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


fclean: clean


re: clean all


.PHONY: all clean fclean re
