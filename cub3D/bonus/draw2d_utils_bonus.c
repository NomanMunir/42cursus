/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:01:53 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 16:54:07 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	create_walls(t_game *game, int i, int j, int flag)
{
	int	color;
	int	height;
	int	width;

	if (flag == 1)
		color = create_trgb(0, 0, 0, 0);
	else
		color = create_trgb(0, 128, 128, 128);
	height = i * game->tile;
	while (height < (i + 1) * game->tile - 1)
	{
		width = j * game->tile;
		while (width < (j + 1) * game->tile - 1)
		{
			set_color(&game->img, width, height, color);
			width++;
		}
		height++;
	}
}

void	create_player(t_game *game)
{
	int	color;
	int	height;
	int	width;
	int	i;
	int	j;

	i = game->ply.y;
	j = game->ply.x;
	create_walls(game, i, j, 0);
	color = create_trgb(0, 255, 0, 0);
	height = (i + game->ply.stepy) * game->tile + game->tile / 2;
	while (height < (i + game->ply.stepy) * game->tile + 1 + game->tile / 2)
	{
		width = (j + game->ply.stepx) * game->tile + game->tile / 2;
		while (width < (j + game->ply.stepx) * game->tile + 1 + game->tile / 2)
		{
			set_color(&game->img, width, height, color);
			width++;
		}
		height++;
	}
}

void	draw_line(t_game *game, t_ray *ray, double x0, double y0)
{
	t_delta	delta;
	int		steps;
	double	x_inc;
	double	y_inc;
	int		i;

	delta.current_x = x0 - ray->ply_x;
	delta.current_y = y0 - ray->ply_y;
	if (abs(delta.current_x) > abs(delta.current_y))
		steps = abs(delta.current_x);
	else
		steps = abs(delta.current_y);
	x_inc = (double)delta.current_x / (double)steps;
	y_inc = (double)delta.current_y / (double)steps;
	i = -1;
	while (++i <= steps)
	{
		set_color(&game->img, ray->ply_x, ray->ply_y, create_trgb(0, 255, 255,
				255));
		ray->ply_x += x_inc;
		ray->ply_y += y_inc;
	}
}

void	put_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j <= game->map->width)
		{
			if (game->map->map[i][j] == '1')
				create_walls(game, i, j, 1);
			else if (game->map->map[i][j] == '0')
				create_walls(game, i, j, 0);
		}
	}
}
