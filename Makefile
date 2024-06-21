SRCS	=	${shell find . -name '*.c'}

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	minesweeper

${NAME}	: ${SRCS}
	cc ${CFLAGS} ${SRCS} -o ${NAME}

clean	:

fclean	:	clean
	rm -f ${NAME}

.PHONY	:	clean fclean