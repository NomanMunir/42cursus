/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:58:34 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 16:25:14 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_move(t_game *game, int key, double *move_x, double *move_y)
{
	if (key == W)
	{
		*move_x = cos(game->ply.rotate + game->ply.dir) * SPEED;
		*move_y = -sin(game->ply.rotate + game->ply.dir) * SPEED;
	}
	if (key == S)
	{
		*move_x = -cos(game->ply.rotate + game->ply.dir) * SPEED;
		*move_y = sin(game->ply.rotate + game->ply.dir) * SPEED;
	}
	if (key == A)
	{
		*move_x = -sin(game->ply.rotate + game->ply.dir) * SPEED;
		*move_y = -cos(game->ply.rotate + game->ply.dir) * SPEED;
	}
	if (key == D)
	{
		*move_x = sin(game->ply.rotate + game->ply.dir) * SPEED;
		*move_y = cos(game->ply.rotate + game->ply.dir) * SPEED;
	}
}

void	set_rotation(t_game *game, int key, int mouse)
{
	if (key == LEFT)
	{
		if (mouse)
			game->ply.rotate += ROTATE / 8;
		else
			game->ply.rotate += ROTATE;
		if (game->ply.rotate > 2 * M_PI)
			game->ply.rotate -= 2 * M_PI;
	}
	else if (key == RIGHT)
	{
		if (mouse)
			game->ply.rotate -= ROTATE / 8;
		else
			game->ply.rotate -= ROTATE;
		if (game->ply.rotate < 0)
			game->ply.rotate += 2 * M_PI;
	}
}

int	check_wall(t_game *game, int x, int y)
{
	if (game->map->map[y][x] != '1' && game->map->map[y][(int)(game->ply.x + 0.5
			+ game->ply.stepx)] != '1' && game->map->map[(int)(game->ply.y + 0.5
			+ game->ply.stepy)][x] != '1' && game->map->map[y][x] != ' '
		&& game->map->map[y][(int)(game->ply.x + 0.5 + game->ply.stepx)] != ' '
		&& game->map->map[(int)(game->ply.y + 0.5 + game->ply.stepy)][x] != ' ')
		return (1);
	return (0);
}

void	move_ply(t_game *game, double move_x, double move_y)
{
	int	x;
	int	y;

	x = (int)(game->ply.x + 0.5 + game->ply.stepx + move_x);
	y = (int)(game->ply.y + 0.5 + game->ply.stepy + move_y);
	if (check_wall(game, x, y))
	{
		game->ply.stepx += move_x;
		game->ply.stepy += move_y;
	}
}

void	hook(t_game *game, int key, int mouse)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	set_move(game, key, &move_x, &move_y);
	set_rotation(game, key, mouse);
	move_ply(game, move_x, move_y);
}
