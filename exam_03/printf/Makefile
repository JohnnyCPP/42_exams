NAME			= main
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
DEBUG_SYMBOLS	= -g3
SOURCE_FILES	= ft_printf.c main.c
DELETE			= rm -f


${NAME}:
	${CC} ${DEBUG_SYMBOLS} ${SOURCE_FILES} -o ${NAME}


all: ${NAME}


clean:
	${DELETE} ${NAME}


re: clean all


sanitize:
	${CC} ${CFLAGS} -fsanitize=address ${DEBUG_SYMBOLS} ${SOURCE_FILES} -o ${NAME}


valgrind:
	valgrind --track-origins=yes -s --leak-check=full --show-leak-kinds=all ./main


.PHONY: all clean re sanitize valgrind
