/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:29:37 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 17:51:15 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	if (draw_map(game))
		return (mlx_free(game), 1);
	return (0);
}

void	init_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 17, 0L, on_destroy, game);
	mlx_loop(game->mlx_ptr);
}
