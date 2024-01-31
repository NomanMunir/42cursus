/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:09:54 by abashir           #+#    #+#             */
/*   Updated: 2024/01/30 13:06:27 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (check_input(ac, av))
		return (1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (panic("Malloc failed"));
	game->array = read_file(av[1]);
	if (!game->array)
		return (free(game), 1);
	game->map = create_map(game->array, game);
	if (!game->map)
		return (free(game), 1);
	if (init_game(game))
		return (ft_free_game(game), 1);
	ft_free_game(game);
	return (0);
}
