NAME	= main
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g3
SFLAGS	= -fsanitize=address
PROGRAM	= ${NAME}.out
OUT	= -o ${PROGRAM}
SOURCES	= ft_printf.c main.c

${NAME}:
	${CC} ${CFLAGS} ${SOURCES} ${OUT}

all: ${NAME}

clean:
	rm ${PROGRAM}

re: clean all

sanitize:
	${CC} ${CFLAGS} ${SFLAGS} ${SOURCES} ${OUT}

valgrind:
	valgrind ./${PROGRAM} -s

.PHONY: clean re sanitize valgrind
