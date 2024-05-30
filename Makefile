# vars
NAME		=	libftprintf.a
INCLUDES	=	include
SRC_DIR		=	src/
SRC_FILES	=	ft_printf
PRT_DIR		=	$(SRC_DIR)argprint/
PRT_FILES	=	print_char print_hex print_nbr  print_percent \
				print_ptr print_str print_unbr
UTIL_DIR	=	$(SRC_DIR)utils/
UTIL_FILES	=	ft_itoa
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDES)

SRCS 	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRCS 	+=	$(addprefix $(PRT_DIR), $(addsuffix .c, $(PRT_FILES)))
SRCS 	+=	$(addprefix $(UTIL_DIR), $(addsuffix .c, $(UTIL_FILES)))
OBJS	=	$(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# main
$(NAME):$(OBJS)
		@ar rcs $(NAME) $(OBJS)
		@echo "✅	Project succesfuly compiled"

all:	$(NAME)

clean:
		@rm -f $(OBJS)
		@echo "✅	Project OBJS cleaned"

fclean:	clean
		@rm -f $(NAME)
		@echo "✅	All compiled project files cleaned"

re:		fclean all
		@echo "✅	Project cleaned and rebuilt"

.PHONY:	all clean fclean re