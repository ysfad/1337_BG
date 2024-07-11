# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 01:55:38 by yakhadad          #+#    #+#              #
#    Updated: 2024/07/02 01:55:44 by yakhadad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = push_swap.c array.c big_sort.c actions.c moves.c checkers.c error.c filler.c small_sort.c
LIBFT =	libft/libft.a
FT_PRINT = ft_printf/libftprintf.a

all: $(NAME)

$(NAME):$(SRC)
	cc $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(FT_PRINT)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all