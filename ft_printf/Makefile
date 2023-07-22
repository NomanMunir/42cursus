# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 12:33:13 by nmunir            #+#    #+#              #
#    Updated: 2023/07/22 21:09:18 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCDIR = include
CFLAGS = -Wall -Werror -Wextra -I$(INCDIR)
CC = cc
OBJS = $(SRC:.c=.o)
SRCDIR = src

SRC =	$(SRCDIR)/ft_printf.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/ft_itoa.c \
		$(SRCDIR)/put_hex.c \
		$(SRCDIR)/ft_put_unsigned_int.c \
		$(SRCDIR)/ft_put_ptr.c \

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re