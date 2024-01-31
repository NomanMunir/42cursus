/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:48:18 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 16:49:20 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	draw_map(t_game *game)
{
	ft_memset(game->img.addr, 0, sizeof(int) * WIDTH * HEIGHT);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (draw_3d(game))
		return (free(game->win_ptr), free(game->mlx_ptr), destroy_texture(game,
				game->texture), 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.ptr, 0, 0);
	return (0);
}
