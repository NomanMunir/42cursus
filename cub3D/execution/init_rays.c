/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:17:55 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 17:02:23 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_first(t_game *game, t_ray *ray)
{
	if (in_range(ray->angle, 180, 360))
		ray->y_h = (int)ray->ply_y / game->tile * game->tile + game->tile;
	else
		ray->y_h = (int)ray->ply_y / game->tile * game->tile - 0.0001;
	ray->x_h = (int)ray->ply_x + ((int)ray->ply_y - ray->y_h) / tan(ray->angle);
	if (in_range(ray->angle, 90, 270))
		ray->x_v = (int)ray->ply_x / game->tile * game->tile - 0.0001;
	else
		ray->x_v = (int)ray->ply_x / game->tile * game->tile + game->tile;
	ray->y_v = (int)ray->ply_y + ((int)ray->ply_x - ray->x_v) * tan(ray->angle);
}

int	wall_hit(double x, double y, t_game *game)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / game->tile);
	y_m = floor(y / game->tile);
	if ((y_m >= game->map->height || y_m < 0 || x_m < 0
			|| game->map->width <= x_m))
		return (0);
	if (game->map->map[y_m] && x_m <= (int)ft_strlen(game->map->map[y_m]))
		if (game->map->map[y_m][x_m] == '1' || game->map->map[y_m][x_m] == ' ')
			return (0);
	return (1);
}

void	find_h_intersection(t_game *game, t_ray *ray)
{
	while (wall_hit(ray->x_h, ray->y_h, game))
	{
		if (in_range(ray->angle, 180, 360))
		{
			ray->y_h = ray->y_h + game->tile;
			ray->x_h = ray->x_h - game->tile / tan(ray->angle);
		}
		else
		{
			ray->y_h = ray->y_h - game->tile;
			ray->x_h = ray->x_h + game->tile / tan(ray->angle);
		}
	}
}

void	find_v_intersection(t_game *game, t_ray *ray)
{
	while (wall_hit(ray->x_v, ray->y_v, game))
	{
		if (in_range(ray->angle, 90, 270))
		{
			ray->x_v = ray->x_v - game->tile;
			ray->y_v = ray->y_v + game->tile * tan(ray->angle);
		}
		else
		{
			ray->x_v = ray->x_v + game->tile;
			ray->y_v = ray->y_v - game->tile * tan(ray->angle);
		}
	}
}
