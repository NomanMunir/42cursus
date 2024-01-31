/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:02:44 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/30 13:54:39 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_ply(t_game *game)
{
	game->ply.x = game->map->player.x;
	game->ply.y = game->map->player.y;
	if (game->map->player.dir_char == 'N')
		game->ply.dir = drad(90);
	else if (game->map->player.dir_char == 'S')
		game->ply.dir = drad(270);
	else if (game->map->player.dir_char == 'E')
		game->ply.dir = drad(0);
	else if (game->map->player.dir_char == 'W')
		game->ply.dir = drad(180);
}

static int	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (panic("mlx_init() failed"));
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, \
		"Welcome to Cub3D!");
	if (!game->win_ptr)
		return (free(game->win_ptr), panic("mlx_new_window() failed"));
	if (create_texture(game, game->texture))
		return (free(game->win_ptr), free(game->mlx_ptr),
			panic("Create texture failed"));
	game->img.ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bitsinpixel, \
		&game->img.line_bytes, &game->img.endian);
	return (0);
}

int	init_game(t_game *game)
{
	t_ray	ray[WIDTH];

	ft_memset(&ray, 0, sizeof(t_ray) * WIDTH);
	game->ray = ray;
	init_ply(game);
	if (init_window(game))
		return (1);
	if (draw_map(game))
		return (1);
	init_hooks(game);
	return (0);
}
