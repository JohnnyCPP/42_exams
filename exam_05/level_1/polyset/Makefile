NAME		= polyset

CXX			= c++
CXXVERSION	= -std=c++98

FORCE_INC	= -include searchable_array_bag.hpp \
			  -include searchable_tree_bag.hpp \
			  -include set.hpp 

INCLUDE		= -I . -I ./provided
CXXFLAGS	= -Wall -Wextra -fpermissive ${FORCE_INC} ${INCLUDE}

SRC			= ./provided/array_bag.cpp \
			  ./provided/tree_bag.cpp \
			  searchable_array_bag.cpp \
			  searchable_tree_bag.cpp \
			  set.cpp \
			  ./provided/main.cpp


all: ${NAME}


${NAME}:
	${CXX} ${CXXFLAGS} ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


fclean: clean


re: clean all


.PHONY: all clean fclean re
