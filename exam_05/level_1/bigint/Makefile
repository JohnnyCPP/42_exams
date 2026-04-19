NAME	= bigint

GCC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= bigint.cpp main.cpp


all: ${NAME}


${NAME}:
	${GCC} ${FLAGS} ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


re: clean all


.PHONY: all, clean, re
