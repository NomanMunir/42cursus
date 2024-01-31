/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:12:21 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 11:39:48 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_ray_height(t_ray *ray, t_game *game, int flag)
{
	if (flag)
	{
		if (in_range(norm_angle(ray->angle), 180, 360))
			ray->hit_horz = SOUTH;
		else
			ray->hit_horz = NORTH;
		ray->h_dist = ray->h_dist * cos(norm_angle(ray->angle - (game->ply.dir \
					+ game->ply.rotate)));
		ray->height = 2 * fabs((game->tile / ray->h_dist) * ((WIDTH) / tan(FOV \
					/ 2)));
	}
	else
	{
		if (in_range(norm_angle(ray->angle), 90, 270))
			ray->hit_vert = WEST;
		else
			ray->hit_vert = EAST;
		ray->v_dist = ray->v_dist * cos(norm_angle(ray->angle - (game->ply.dir \
					+ game->ply.rotate)));
		ray->height = 2 * fabs((game->tile / ray->v_dist) * ((WIDTH) / tan(FOV \
					/ 2)));
	}
}

void	init_each_ray(t_ray *ray, t_game *game)
{
	set_boundary(game, ray);
	ray->h_dist = find_distance(ray, 1);
	ray->v_dist = find_distance(ray, 0);
	if (ray->h_dist < ray->v_dist)
		calculate_ray_height(ray, game, 1);
	else
		calculate_ray_height(ray, game, 0);
	ray->top_pix = (HEIGHT / 2) - (ray->height / 2);
	ray->bot_pix = (HEIGHT / 2) + (ray->height / 2);
	if (ray->top_pix < 0)
		ray->top_pix = 0;
	if (ray->bot_pix > HEIGHT)
		ray->bot_pix = HEIGHT;
}

void	init_rays_3d(t_game *game)
{
	double	angle;
	int		i;

	i = -1;
	while (++i < WIDTH)
		set_range(game, &game->ray[i]);
	angle = game->ply.dir + game->ply.rotate - drad(FOV / 2);
	i = WIDTH - 1;
	while (i != -1)
	{
		game->ray[i].angle = angle;
		if (cos(game->ray[i].angle) == 0)
			game->ray[i].angle += 0.0001;
		find_first(game, &game->ray[i]);
		find_h_intersection(game, &game->ray[i]);
		find_v_intersection(game, &game->ray[i]);
		init_each_ray(&game->ray[i], game);
		angle += drad(FOV) / WIDTH;
		i--;
	}
}
