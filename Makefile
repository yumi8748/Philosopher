NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/actions.c src/init.c src/main.c src/threads.c src/utils.c src/libft.c
OBJ = $(SRC:.c=.o)
INC = -I inc/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
