LIBFTPATH = ./libft/
NAME = 		ft_ls
CC = 		clang
CFLAGS = 	-Wall -Werror -Wextra
SRC = 		main.c\
			readdir.c\
			ft_lstadd_to_head.c\
			libft/libft.a
OBJ =		main.o\
			ft_lstadd_to_head.o\
		   	test.o

all:$(NAME)

$(NAME):
	make -C $(LIBFTPATH)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

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
