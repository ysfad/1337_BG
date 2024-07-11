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
SRC = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(SRC)
	cc $(CFLAGS) -o $(NAME) $(SRC) $(PRINTF) $(LIBFT)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all