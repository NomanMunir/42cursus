/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:30:58 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/30 13:52:57 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_dem(char **map_ptr, t_map *map)
{
	int	i;

	i = 0;
	map->width = ft_strlen(map_ptr[0]);
	while (map_ptr[i])
	{
		if (map->width < (int)ft_strlen(map_ptr[i]))
			map->width = (int)ft_strlen(map_ptr[i]);
		i++;
	}
	map->height = i;
}

static int	allocate_2dmap(t_map *map, char **split, int map_ptr)
{
	int	j;

	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		return (panic("Malloc error"));
	j = 0;
	while (split[map_ptr])
	{
		map->map[j] = ft_calloc(map->width + 1, sizeof(char));
		if (!map->map[j])
			return (free_array(map->map), panic("Malloc error"));
		ft_memset(map->map[j], ' ', map->width);
		ft_strlcpy(map->map[j], split[map_ptr], ft_strlen(split[map_ptr]) + 1);
		map->map[j][ft_strlen(split[map_ptr++])] = ' ';
		map->map[j++][map->width] = '\0';
	}
	map->map[j] = NULL;
	return (0);
}

int	init_map(char **split, t_map *map)
{
	int	map_ptr;

	map_ptr = find_ptr(split);
	if (map_ptr == 0)
		return (panic("Map not found!"));
	set_dem(split + map_ptr, map);
	if (allocate_2dmap(map, split, map_ptr))
		return (1);
	if (map_checker(map))
		return (free_array(map->map), 1);
	return (0);
}
