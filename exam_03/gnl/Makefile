NAME			= main
BUFFER_VAL		= 28
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
DEBUG_SYMBOLS	= -g3
DEFINE_BUFFER	= -D BUFFER_SIZE=${BUFFER_VAL}
SOURCE_FILES	= get_next_line.c main.c
DELETE			= rm -f


${NAME}:
	${CC} ${CFLAGS} ${DEBUG_SYMBOLS} ${DEFINE_BUFFER} ${SOURCE_FILES} -o ${NAME}


all: ${NAME}


clean:
	${DELETE} ${NAME}


re: clean all


sanitize:
	${CC} ${CFLAGS} -fsanitize=address ${DEBUG_SYMBOLS} ${DEFINE_BUFFER} ${SOURCE_FILES} -o ${NAME}


valgrind:
	valgrind --track-origins=yes -s --leak-check=full --show-leak-kinds=all ./main ./files_to_read/file_4.txt


.PHONY: all clean re sanitize valgrind
