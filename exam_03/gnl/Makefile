# file name
NAME			= main

# value of preprocessor definition
BUFFER_VAL		= 28

# c compiler and flags
CC			= cc
CFLAGS			= -Wall -Wextra -Werror
DEBUG_SYMBOLS		= -g

# defines the preprocessor macro "BUFFER_SIZE" with a value of "BUFFER_VAL"
DEFINE_BUFFER		= -D BUFFER_SIZE=${BUFFER_VAL}

SOURCE_FILES	= get_next_line_utils.c get_next_line.c main.c
BONUS_FILES		= get_next_line_utils_bonus.c get_next_line_bonus.c main_bonus.c

DELETE			= rm -f

${NAME}:
	${CC} ${DEBUG_SYMBOLS} ${CFLAGS} ${DEFINE_BUFFER} ${SOURCE_FILES} -o ${NAME}

bonus:
	${CC} ${DEBUG_SYMBOLS} ${CFLAGS} ${DEFINE_BUFFER} ${BONUS_FILES} -o main_bonus

# default rule, compiles the program
all: ${NAME}

# deletes the program
clean:
	${DELETE} ${NAME}

re: clean all
