LIBFTPATH = ./libft/
NAME = ft_ls
CC = clang
CFLAGS = -Wall -Werror -Wextra
SRC = test.c
OBJ = test.o

all:$(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS)
	make -C $(LIBFTPATH)

clean:
	make -C $(LIBFTPATH) clean

fclean:
	make -C $(LIBFTPATH) fclean
	echo "\033[31;1m$(LIBFTPATH) removed!\033[0m"

re:
	make -C $(LIBFTPATH) re
