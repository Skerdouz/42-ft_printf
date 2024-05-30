# vars
NAME		=	libftprintf.a
LIBFT		=	libft
INCLUDES	=	include
SRC_DIR		=	src/
SRC_FILES	=	ft_printf
SSRC_DIR	=	$(SRC_DIR)argprint/
SSRC_FILES	=	print_char print_nbr print_str print_unbr
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDES)

SRCS 	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRCS 	+=	$(addprefix $(SSRC_DIR), $(addsuffix .c, $(SSRC_FILES)))
OBJS	=	$(SRCS:.c=.o)

# main
$(NAME):$(OBJS)
		@make -C $(LIBFT)
		@mv $(LIBFT)/libft.a .
		@mv libft.a $(NAME)
		@ar rcs $(NAME) $(OBJS)
		@echo "\nProject succesfuly compiled✅"

all:	$(NAME)

clean:
		@rm -f $(OBJS)
		@make clean -C $(LIBFT)
		@echo "\nProject OBJS cleaned✅"

fclean:	clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)
		@echo "\nProject OBJS & EXE cleaned✅"

re:		fclean all
		@echo "\nProject cleaned and rebuilt✅"

.PHONY:	all clean fclean re