NAME		= vect2

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= vect2.cpp main.provided.cpp


all: ${NAME}


${NAME}:
	${CXX} ${CXXFLAGS} ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


re: clean all


.PHONY: all, clean, re
