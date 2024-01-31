/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:48:07 by abashir           #+#    #+#             */
/*   Updated: 2024/01/30 13:10:43 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int	destroy_texture(t_game *game, t_texture *t)
{
	if (t->no_img.ptr)
		mlx_destroy_image(game->mlx_ptr, t->no_img.ptr);
	if (t->so_img.ptr)
		mlx_destroy_image(game->mlx_ptr, t->so_img.ptr);
	if (t->we_img.ptr)
		mlx_destroy_image(game->mlx_ptr, t->we_img.ptr);
	if (t->ea_img.ptr)
		mlx_destroy_image(game->mlx_ptr, t->ea_img.ptr);
	return (1);
}

void	ft_free_game(t_game *game)
{
	free_array(game->map->split);
	free_array(game->map->map);
	free(game->texture);
	free(game->map);
	free(game);
	game = NULL;
}

void	mlx_free(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	destroy_texture(game, game->texture);
	ft_free_game(game);
	exit(1);
}
