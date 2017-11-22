LIBFTPATH = ./libft/
NAME = 		ft_ls
CC = 		clang
CFLAGS = 	-Wall -Werror -Wextra
SRC = 		main.c\
			readdir.c\
			ft_lstadd_to_head.c\
			arg_check.c\
			init_struct.c\
			new_node.c\
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
