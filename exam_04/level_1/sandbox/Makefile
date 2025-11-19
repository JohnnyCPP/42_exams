NAME	= sandbox
SRC		= sandbox.c main.c


all: ${NAME}


${NAME}:
	cc ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


fclean: clean


re: clean all


.PHONY: all clean fclean re
