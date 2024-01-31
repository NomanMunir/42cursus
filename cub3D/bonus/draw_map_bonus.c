/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:02:44 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 17:48:47 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	draw_map(t_game *game)
{
	ft_memset(game->img.addr, 0, sizeof(int) * WIDTH * HEIGHT);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (draw_3d(game))
		return (mlx_free(game), 1);
	if (game->show_map)
		draw_2d(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.ptr, 0, 0);
	return (0);
}
