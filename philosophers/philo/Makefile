# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 13:43:37 by abashir           #+#    #+#              #
#    Updated: 2023/12/31 16:47:40 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -pthread -Wall -Wextra -Werror

SRCS =	src/main.c src/init.c src/parsing.c \
		src/actions/forks.c src/actions/routine.c src/actions/utils_actions.c \
		src/monitor/monitor.c \
		src/utils/error.c src/utils/utils.c \

INC =	includes

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $(OBJS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(INC)

.PHONY: all clean fclean re
