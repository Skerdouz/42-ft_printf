NAME	=	libftprintf.a
SRCS	=	srcs/ft_printf.c srcs/print_char.c
OBJS	=	${SRCS:.c=.o}
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I includes

${NAME}:	${OBJS}
			ar rsc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re