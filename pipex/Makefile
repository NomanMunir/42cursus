# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/10/05 10:55:06 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft

SRC = 	main.c \
		src/parsing.c \
		src/init_pipe.c \
		src/utils.c \
		src/error_handling.c \
		src/execution.c \
		src/handling_files.c \
		libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c \
		

BSRC =	bonus/main_bonus.c \
		bonus/parsing_bonus.c \
		bonus/init_pipe_bonus.c \
		bonus/utils_bonus.c \
		bonus/error_handling_bonus.c \
		bonus/execution_bonus.c \
		bonus/handling_files_bonus.c \
		libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c \

INC = -I get_next_line -I include -I libs/libft
ARC = libs/libft/libft.a
CC = cc

CFLAGS = $(INC) -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(ARC) -o $(NAME)
	
bonus: $(LIBFT)
	$(CC) $(CFLAGS) $(BSRC) $(ARC) -o $(NAME)
	
$(LIBFT):
	cd libs/libft && make
	
clean:
	cd libs/libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libs/libft && make fclean

re: fclean all

norm:
	norminette $(SRC) $(BSRC) include bonus/pipex_bonus.h
	cd libs/libft && make norm
	
.PHONY: all clean fclean re libft bonus norm
