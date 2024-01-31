/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:29:37 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 17:52:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	on_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	destroy_texture(game, game->texture);
	free(game->mlx_ptr);
	ft_free_game(game);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		on_destroy(game);
	else if (keycode == W)
		hook(game, W, 0);
	else if (keycode == S)
		hook(game, S, 0);
	else if (keycode == A)
		hook(game, A, 0);
	else if (keycode == D)
		hook(game, D, 0);
	else if (keycode == LEFT)
		hook(game, LEFT, 0);
	else if (keycode == RIGHT)
		hook(game, RIGHT, 0);
	else if (keycode == MAP_KEY)
		game->show_map = !game->show_map;
	else if (keycode == MOUSE)
		game->enable_mouse = !game->enable_mouse;
	if (draw_map(game))
		return (1);
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	if (game->enable_mouse)
	{
		game->mouse.previous_x = game->mouse.current_x;
		game->mouse.previous_y = game->mouse.current_y;
		game->mouse.current_x = x;
		game->mouse.current_y = y;
		if (x > 0 && x < WIDTH)
		{
			if (game->mouse.current_x > game->mouse.previous_x)
				hook(game, RIGHT, 1);
			else if (game->mouse.current_x < game->mouse.previous_x)
				hook(game, LEFT, 1);
		}
		if (draw_map(game))
			return (mlx_free(game), 1);
	}
	return (0);
}

void	init_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 17, 0L, on_destroy, game);
	mlx_hook(game->win_ptr, 6, 0, mouse_move, game);
	mlx_loop(game->mlx_ptr);
}
