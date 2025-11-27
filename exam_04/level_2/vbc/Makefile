NAME	= vbc
SRC		= vbc.c


all: ${NAME}


${NAME}:
	cc -g3 -I ./ ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


fclean: clean


re: clean all


.PHONY: all clean fclean re
