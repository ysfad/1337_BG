# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 00:10:52 by yakhadad          #+#    #+#              #
#    Updated: 2023/11/26 15:15:53 by yakhadad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
FTS =	ft_isalpha.c ft_isprint.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_memmove.c ft_memcpy.c\
		ft_atoi.c ft_isascii.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_memset.c ft_isalnum.c\
		ft_isdigit.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_bzero.c ft_memcmp.c ft_memchr.c ft_calloc.c\
	   	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

FTSO = $(FTS:.c=.o)
NAME = libft.a

$(NAME):$(FTSO)
	ar -r $(NAME) $(FTSO)

all : $(NAME)

clean :
	rm -rf $(FTSO)

fclean : clean
	rm -rf $(NAME)

re : fclean all