/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:08:57 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/30 13:29:52 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_valid_char(t_map *map, int y)
{
	int	x;

	x = -1;
	while (map->map[y][++x])
	{
		if (!my_strchr("01NSEW ", map->map[y][x]))
			return (panic("Invalid character in map"));
	}
	return (0);
}

int	find_player(t_map *map)
{
	int	x;
	int	y;
	int	count_player;

	y = 0;
	count_player = 0;
	while (map->map[y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (my_strchr("NSEW", map->map[y][x]))
			{
				map->player.x = x;
				map->player.y = y;
				map->player.dir_char = map->map[y][x];
				count_player++;
			}
		}
		y++;
	}
	if (count_player > 1 || count_player == 0)
		return (1);
	return (0);
}

int	check_around(char **b_map)
{
	t_point	p;

	p.y = 0;
	while (b_map[p.y])
	{
		p.x = 0;
		while (b_map[p.y][p.x])
		{
			if (b_map[p.y][p.x] == ' ')
			{
				if (b_map[p.y][p.x + 1] == 'F' || b_map[p.y][p.x - 1] == 'F'
					|| b_map[p.y + 1][p.x] == 'F' || b_map[p.y - 1][p.x] == 'F')
					return (panic("Map is not enclosed/check spaces"));
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

int	loop_around(char *s, int index, t_map *map)
{
	int	i;

	i = 0;
	ft_skip_spaces(s, &i);
	if (index == 0 || index == map->height - 1)
	{
		while (s[i])
		{
			if (s[i] != '1' && s[i] != ' ')
				return (panic("Map is not enclosed"));
			i++;
		}
		return (0);
	}
	i = 0;
	ft_skip_spaces(s, &i);
	if (s[i] != '1')
		return (panic("Map is not enclosed"));
	while (s[i])
		i++;
	while (s[--i] == ' ')
		;
	if (s[i] != '1')
		return (panic("Map is not enclosed"));
	return (0);
}

int	map_checker(t_map *map)
{
	int		i;
	char	**map_w_border;

	i = -1;
	if (find_player(map))
		return (panic("Invalid number of players"));
	map_w_border = add_border(map);
	if (!map_w_border)
		return (1);
	map_w_border[(int)map->player.y + 1][(int)map->player.x + 1] = '0';
	flood_fill(map_w_border, (t_point){map->height + 2, map->width + 2},
		(t_point){map->player.y + 1, map->player.x + 1}, '0');
	if (check_around(map_w_border))
		return (free_array(map_w_border), 1);
	while (map->map[++i])
	{
		if (check_valid_char(map, i))
			return (free_array(map_w_border), 1);
		if (loop_around(map->map[i], i, map))
			return (free_array(map_w_border), 1);
	}
	return (free_array(map_w_border), 0);
}
