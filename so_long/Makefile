# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/09/10 13:01:24 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		create_map.c \
		utils.c \
		validate_map.c \
		validate_path.c \
		error.c \
		events.c \
		init_game.c \
		move.c \
		so_long.c \
		
OBJ = $(SRC:.c=.o)
ARC = libft/libft.a minilibx/libmlx.a
CC = cc

CFLAGS = -Wall -Werror -Wextra
FFLAGS = -framework OpenGL -framework AppKit

all: libft minilibx
	$(CC) $(SRC) $(CFLAGS) $(FFLAGS) $(ARC) -o $(NAME)
	
libft:
	cd libft && make

minilibx:
	cd minilibx && make

clean:
	rm -f -v $(OBJ) libft/*.o minilibx/*.o
	
fclean: clean
	rm -f $(NAME) libft/*.a minilibx/*.a

re: fclean all

norm:
	norminette $(SRC) so_long.h

.PHONY: all clean fclaen re libft minilibx