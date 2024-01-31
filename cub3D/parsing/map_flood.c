/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:51:29 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/28 17:11:06 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	set_border(t_map *map, char **copy, int i)
{
	if (i == 0)
	{
		copy[0] = ft_calloc(map->width + 3, sizeof(char));
		if (!copy[0])
			return (free_array(copy), panic("Malloc error"));
		ft_memset(copy[0], 'B', map->width + 2);
	}
	else
	{
		copy[i] = ft_calloc(map->width + 3, sizeof(char));
		if (!copy[i])
			return (free_array(copy), panic("Malloc error"));
		ft_memset(copy[i], 'B', map->width + 2);
		copy[i][map->width + 2] = '\0';
		copy[i + 1] = NULL;
	}
	return (0);
}

static int	fill_border(t_map *map, int *i, char **copy)
{
	int	j;

	while (map->map[*i])
	{
		j = 0;
		copy[(*i) + 1] = ft_calloc(map->width + 3, sizeof(char));
		if (!copy[(*i) + 1])
			return (panic("Malloc error"));
		ft_memset(copy[(*i) + 1], 'B', map->width + 2);
		while (map->map[(*i)][j])
		{
			copy[(*i) + 1][j + 1] = map->map[(*i)][j];
			j++;
		}
		copy[(*i) + 1][j + 2] = '\0';
		(*i)++;
	}
	return (0);
}

char	**add_border(t_map *map)
{
	int		i;
	char	**copy;

	i = 0;
	copy = ft_calloc(map->height + 3, sizeof(char *));
	if (!copy)
		return (panic("Malloc error"), NULL);
	if (set_border(map, copy, i))
		return (NULL);
	if (fill_border(map, &i, copy))
		return (free_array(copy), NULL);
	if (set_border(map, copy, i + 1))
		return (NULL);
	return (copy);
}

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y >= size.y || cur.x >= size.x || (tab[cur.x][cur.y] != to_fill))
		return ;
	tab[cur.x][cur.y] = 'F';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}
