/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:32:38 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/30 13:36:58 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../include/cub3d.h"

int		draw_2d(t_game *game);
void	put_walls(t_game *game);
void	create_player(t_game *game);
void	draw_line(t_game *game, t_ray *ray, double x, double y);
void	create_walls(t_game *game, int i, int j, int flag);

#endif