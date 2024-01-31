/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:38:23 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 17:53:09 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_ceiling(t_game *game)
{
	int	i;
	int	j;
	int	*color;
	int	rgb;

	i = 0;
	color = game->texture->ceiling;
	rgb = create_trgb(0, color[0], color[1], color[2]);
	while (i < WIDTH)
	{
		j = 0;
		while (j < game->ray[i].top_pix)
		{
			set_color(&game->img, i, j, rgb);
			j++;
		}
		i++;
	}
}

static void	draw_floor(t_game *game)
{
	int	i;
	int	j;
	int	rgb;
	int	*color;

	color = game->texture->floor;
	i = 0;
	rgb = create_trgb(0, color[0], color[1], color[2]);
	while (i < WIDTH)
	{
		j = game->ray[i].bot_pix;
		while (j < HEIGHT)
		{
			set_color(&game->img, i, j, rgb);
			j++;
		}
		i++;
	}
}

int	draw_3d(t_game *game)
{
	game->tile = TILE_3D;
	init_rays_3d(game);
	draw_walls_3d(game);
	draw_ceiling(game);
	draw_floor(game);
	ft_memset(game->ray, 0, sizeof(t_ray) * WIDTH);
	return (0);
}
