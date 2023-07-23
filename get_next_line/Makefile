# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 14:25:09 by nmunir            #+#    #+#              #
#    Updated: 2023/07/23 16:00:03 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
INCDIR = include
CFLAGS = -Wall -Werror -Wextra -I$(INCDIR)
CC = cc $(CFLAGS)
SRCDIR = src

SRC =	$(SRCDIR)/get_next_line.c \
		$(SRCDIR)/get_next_line_utils.c \
		

OBJS = $(SRC:.c=.o)

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