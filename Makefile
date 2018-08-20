LIBFTPATH = ./libft/
NAME 			= ft_ls
CC 				= clang
CFLAGS 		= #-Wall -Werror -Wextra
SRC 			= main.c\
						arg_check.c\
						arg_check1.c\
						readdir.c\
						new_node.c\
						ft_lstadd_to_head.c\
						print_lst.c\
						sort_lst.c\
						swap_fields.c\
						printing.c\
						recursion.c\
						libft/libft.a
OBJ =

all:$(NAME)

$(NAME):
	make -C $(LIBFTPATH)
	$(CC) -o $(NAME) -g $(SRC) $(CFLAGS)

clean:
	make -C $(LIBFTPATH) clean

fclean:
	make -C $(LIBFTPATH) fclean
	echo "\033[31;1m$(LIBFTPATH) removed!\033[0m"
	rm -f $(NAME)
	echo "\033[31;1m$(NAME) removed!\033[0m"

re:
	make -C $(LIBFTPATH) re
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)
