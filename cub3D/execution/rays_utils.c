/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:18:34 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/23 16:29:05 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	find_distance(t_ray *ray, int flag)
{
	if (flag)
		return (sqrt(pow(ray->ply_x - ray->x_h, 2) + pow(ray->ply_y - ray->y_h,
					2)));
	else
		return (sqrt(pow(ray->ply_x - ray->x_v, 2) + pow(ray->ply_y - ray->y_v,
					2)));
}

void	set_boundary(t_game *game, t_ray *ray)
{
	if (ray->x_h < 0 || ray->x_h > game->map->width * game->tile)
		ray->x_h = 10000000;
	if (ray->x_v < 0 || ray->x_v > game->map->width * game->tile)
		ray->x_v = 10000000;
	if (ray->y_h < 0 || ray->y_h > game->map->height * game->tile)
		ray->y_h = 10000000;
	if (ray->y_v < 0 || ray->y_v > game->map->height * game->tile)
		ray->y_v = 10000000;
}

void	set_range(t_game *game, t_ray *ray)
{
	if (game->ply.rotate + game->ply.dir - drad(FOV / 2) > drad(360))
		game->ply.rotate -= drad(360);
	if (game->ply.rotate + game->ply.dir - drad(FOV / 2) < 0)
		game->ply.rotate += drad(360);
	ray->angle = game->ply.dir + game->ply.rotate - drad(FOV / 2);
	ray->ply_x = (game->ply.x + 0.5 + game->ply.stepx) * game->tile;
	ray->ply_y = (game->ply.y + 0.5 + game->ply.stepy) * game->tile;
}

int	in_boundry(t_game *game, double x, double y)
{
	if (x < 0 || x > game->map->width * game->tile || y < 0
		|| y > game->map->height * game->tile)
		return (0);
	return (1);
}

double	norm_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
