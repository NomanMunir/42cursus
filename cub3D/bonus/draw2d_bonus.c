/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:33:20 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/30 15:23:34 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int	set_tile_size(t_game *game)
{
	int	tile_h;
	int	tile_w;

	tile_h = HEIGHT / (game->map->height);
	while (tile_h * game->map->height > HEIGHT / 4)
		tile_h = tile_h / 2;
	tile_w = WIDTH / (game->map->width);
	while (tile_w * game->map->width > WIDTH / 4)
		tile_w = tile_w / 2;
	game->tile = fmin(tile_h, tile_w);
	if (game->tile < 6)
		return (panic("Map is out of range."));
	return (0);
}

static void	find_intersections(t_game *game)
{
	t_ray	ray;

	set_range(game, &ray);
	ray.angle = game->ply.dir + game->ply.rotate;
	find_first(game, &ray);
	find_h_intersection(game, &ray);
	find_v_intersection(game, &ray);
	set_boundary(game, &ray);
	ray.h_dist = find_distance(&ray, 1);
	ray.v_dist = find_distance(&ray, 0);
	if (ray.h_dist <= ray.v_dist)
		draw_line(game, &ray, ray.x_h, ray.y_h);
	else
		draw_line(game, &ray, ray.x_v, ray.y_v);
}

int	draw_2d(t_game *game)
{
	if (set_tile_size(game))
		return (1);
	put_walls(game);
	create_player(game);
	find_intersections(game);
	return (0);
}
