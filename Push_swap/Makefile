# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/09/25 13:43:52 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker

SRC =	init_stack.c \
		utils.c \
		parsing.c \
		errors.c \
		sorting.c \
		init_nodes.c \
		push_swap.c \
		operations/pushs.c \
		operations/rotates.c \
		operations/rrotates.c \
		operations/swaps.c \

BSRC =	bonus_checker/checker_bonus.c \
		bonus_checker/checker_utils_bonus.c \
		lib/get_next_line/get_next_line.c \
		lib/get_next_line/get_next_line_utils.c \

INC = lib/get_next_line
ARC = lib/libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: libft
	$(CC) $(CFLAGS) main.c $(SRC) $(ARC) -o $(NAME)

bonus: libft
	$(CC) $(CFLAGS) -I $(INC) $(BSRC) $(SRC) $(ARC) -o $(BNAME)

libft:
	cd lib/libft && make

clean:
	rm -f -v $(OBJ) $(BOBJ)
	cd lib/libft && make clean
	
fclean: clean
	rm -f $(NAME) $(BNAME)
	cd lib/libft && make fclean

re: fclean all

norm:
	norminette $(SRC) $(BSRC) $(INC) push_swap.h
	norminette bonus_checker/checker_bonus.h
	cd lib/libft && make norm

.PHONY: all clean fclean re libft norm bonus
