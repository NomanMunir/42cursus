# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 13:43:37 by abashir           #+#    #+#              #
#    Updated: 2023/12/31 11:48:56 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -pthread -Wall -Wextra -Werror

SRCS =	main.c parsing/parsing.c init.c \
 		actions/actions.c actions/monitor.c \
		utils/errors.c utils/utils.c\
		
OBJS = $(SRCS:.c=.o)
NAME = philo_bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) philo_bonus.h

.PHONY: all clean fclean re
