CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread -g3
NAME = philo
SRC = philo.c actions.c routine.c utils.c

all: $(NAME)

$(NAME): $(SRC)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
