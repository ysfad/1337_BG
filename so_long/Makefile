# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 04:56:29 by yakhadad          #+#    #+#              #
#    Updated: 2024/07/11 04:56:37 by yakhadad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c checkers* fillers.c moves.c image.c errors.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	make -s -C libft
	make -s -C ft_printf
	cc $(CFLAGS) $(SRC) $(PRINTF) $(LIBFT) -lmlx -lXext -lX11 -o $(NAME) 

clean:
	rm -f $(NAME)
	make -C libft fclean -s
	make -C ft_printf fclean -s

fclean: clean

re: clean all