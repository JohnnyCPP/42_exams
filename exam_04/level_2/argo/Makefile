NAME	= argo
SRC		= argo.c given.c


all: ${NAME}


${NAME}:
	cc -g3 ${SRC} -o ${NAME}


clean:
	rm -f ${NAME}


fclean: clean


re: clean all


.PHONY: all clean fclean re
