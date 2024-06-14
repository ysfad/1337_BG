# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 19:26:07 by yakhadad          #+#    #+#              #
#    Updated: 2023/12/06 19:26:20 by yakhadad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
FTS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putadrs.c ft_putnbr_base.c ft_unsigned.c
FTSO = $(FTS:.c=.o)
NAME = libftprintf.a

$(NAME):$(FTSO)
	ar -rc $(NAME) $?

all: $(NAME)

clean:
	rm -f $(FTSO)

fclean: clean
	rm -f $(NAME)

re: fclean all