# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 15:09:40 by abashir           #+#    #+#              #
#    Updated: 2024/01/30 15:31:53 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -I include -Wall -Wextra -Werror #-g3 -fsanitize=address

FFLAGS = -framework OpenGL -framework AppKit

SRCS = main.c \
       utils/utils.c utils/error.c utils/free.c utils/main_utils.c \
	   parsing/parsing_utils.c parsing/create_map.c parsing/init_map.c \
	   parsing/validate_texture.c parsing/validate_map.c parsing/map_flood.c \
	   execution/init_game.c execution/execution_utils.c \
	   execution/draw_map.c \
	   execution/init_rays.c execution/rays_utils.c \
	   execution/draw3d.c execution/draw3d_render.c execution/draw3d_ray.c \
	   events/hooks.c events/hooks_utils.c \

SRCSB = bonus/draw_map_bonus.c bonus/hooks_bonus.c \
	   	bonus/draw2d_bonus.c bonus/draw2d_utils_bonus.c \
		main.c \
		utils/utils.c utils/error.c utils/free.c utils/main_utils.c \
		parsing/parsing_utils.c parsing/create_map.c parsing/init_map.c \
		parsing/validate_texture.c parsing/validate_map.c parsing/map_flood.c \
		execution/init_game.c execution/execution_utils.c \
		execution/init_rays.c execution/rays_utils.c \
		execution/draw3d.c execution/draw3d_render.c execution/draw3d_ray.c \
		events/hooks_utils.c \

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

ARC = libs/libft/libft.a libs/minilibx/libmlx.a

NAME = cub3D

NAME_B = cub3D_bonus

all: $(NAME)

$(NAME): $(OBJS) $(ARC)
	$(CC) $(CFLAGS) $(FFLAGS) $(OBJS) $(ARC) -o $(NAME)

bonus: $(OBJSB) $(ARC)
	$(CC) $(CFLAGS) $(FFLAGS) $(OBJSB) $(ARC) -o $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ARC):
	@make -C libs/libft
	@make -C libs/minilibx

clean:
	@rm -f $(OBJS) $(OBJSB)
	cd libs/libft && make clean
	cd libs/minilibx && make clean

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	cd libs/libft && make fclean
	cd libs/minilibx && make fclean

re: fclean all

norm:
	norminette $(SRCS) $(SRCSB) include
	cd libs/libft && make norm

.PHONY: all clean fclean re norm $(LIBFT)
