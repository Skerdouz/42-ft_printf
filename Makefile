# colors
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

_IGREY=$'\x1b[40m'
_IRED=$'\x1b[41m'
_IGREEN=$'\x1b[42m'
_IYELLOW=$'\x1b[43m'
_IBLUE=$'\x1b[44m'
_IPURPLE=$'\x1b[45m'
_ICYAN=$'\x1b[46m'
_IWHITE=$'\x1b[47m'

# vars
NAME		=	libftprintf.a
LIBFT		=	libft
INCLUDES	=	include
SRC_DIR		=	src/
SRC_FILES	=	ft_print
SSRC_DIR	=	$(SRC_DIR)argprint/
SSRC_FILES	=	print_hex print_percent print_pointer print_udec
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDES)

SRCS 	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRCS 	+=	$(addprefix $(SSRC_DIR), $(addsuffix .c, $(SSRC_FILES)))
OBJS	=	$(SRCS:.c=.o)

# main
$(NAME):$(OBJS)
		make -C $(LIBFT)
		mv $(LIBFT)/libft.a .
		mv libft.a $(NAME)
		ar rcs $(NAME) $(OBJS)
		@echo "$(_IGREEN)libftprintf.a succesfuly compiled.$(DEF_COLOR)"

all:	$(NAME)

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		@echo "$(_IBLUE)objs cleaned.$(DEF_COLOR)"

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
		@echo "$(_ICYAN)objs & exe cleaned.$(DEF_COLOR)"

re:		fclean all
	@echo "$(_IWHITE)cleaned and rebuilt$(DEF_COLOR)"

.PHONY:	all clean fclean re