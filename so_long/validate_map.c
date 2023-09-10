/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:43:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/10 13:23:52 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_rect(t_map map)
{
	int	i;

	i = 1;
	while (i < map.size.x)
	{
		if (ft_strlen(map.plot[i]) != ft_strlen(map.plot[i - 1]))
			handle_error_free(1, map.plot);
		i++;
	}
}

void	is_map_closed(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.size.x)
	{
		j = -1;
		if (map.plot[i][0] != '1' || map.plot[i][map.size.y - 1] != '1')
			handle_error_free(2, map.plot);
		if (i == 0 || i == map.size.x - 1)
		{
			while (map.plot[i][++j])
			{
				if (map.plot[i][j] != '1')
					handle_error_free(2, map.plot);
			}
		}
	}
}

int	counter(t_map *game, char ch)
{
	int		count;
	int		i;
	int		j;
	int		k;

	i = 0;
	count = 0;
	k = 0;
	while (i < (game)->size.x)
	{
		j = ft_strspn(game->plot[i], ch);
		if (j != 0)
		{
			k = ft_strc(game->plot[i], ch);
			count += j;
			if (ch == 'E')
				(*game).e = (t_point){i, k};
			if (ch == 'P')
				(*game).s = (t_point){i, k};
		}
		i++;
	}
	if (ch == 'C')
		(*game).c = count;
	return (count);
}

void	count(t_map *game)
{
	size_t		e;
	size_t		s;
	size_t		c;

	c = counter(game, 'C');
	e = counter(game, 'E');
	s = counter(game, 'P');
	if (!(c > 0 && e == 1 && s == 1))
		handle_error_free(8, game->plot);
}

void	check_map(t_map *game, char *av)
{
	is_map_rect(*game);
	is_map_closed(*game);
	count(game);
	find_collects(game, game->c);
	contain_invalid(game);
	check_path(*game, av);
}
