/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:02:12 by abashir           #+#    #+#             */
/*   Updated: 2023/09/08 18:53:12 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game *game, int x, int y)
{
	if (game->map.s.y + x < game->map.size.y \
	&& game->map.s.x + y < game->map.size.x)
	{
		if (game->map.plot[game->map.s.x + y][game->map.s.y] != '1' \
		&& game->map.plot[game->map.s.x][game->map.s.y + x] != '1')
		{
			return (1);
		}
	}
	return (0);
}

void	check_end(t_game *game, int x, int y)
{
	if (game->map.plot[game->map.s.x + y][game->map.s.y + x] == 'E')
	{
		if (game->map.c == 0)
		{
			ft_putstr_fd("You have completed the game in ", 2);
			ft_putnbr_fd(game->steps, 2);
			ft_putstr_fd(" steps!\n", 2);
			on_destroy(game);
		}
		else
			ft_putstr_fd("You need to collect all the collectables!\n", 2);
	}
}

void	move(t_game *game, int x, int y)
{
	if (check_move(game, x, y))
	{
		check_end(game, x, y);
		if (game->map.plot[game->map.s.x + y][game->map.s.y + x] != 'E')
		{
			mlx_clear_window(game->mlx_ptr, game->win_ptr);
			game->map.plot[game->map.s.x][game->map.s.y] = '0';
			game->map.s.y += x;
			game->map.s.x += y;
			if (game->map.plot[game->map.s.x][game->map.s.y] == 'C')
				game->map.c--;
			game->map.plot[game->map.s.x][game->map.s.y] = 'P';
			draw_map(game);
			game->steps++;
		}
		ft_putstr_fd("Steps: ", 2);
		ft_putnbr_fd(game->steps, 2);
		ft_putchar_fd('\n', 2);
	}
}
