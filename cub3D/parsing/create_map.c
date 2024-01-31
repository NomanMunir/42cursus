/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:43:16 by abashir           #+#    #+#             */
/*   Updated: 2024/01/31 11:18:22 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*null_terminate(char *array)
{
	char	*end;

	end = array;
	while (*end)
		end++;
	end--;
	while (end && my_strchr(" \n", *end))
		end--;
	end++;
	*end = '\0';
	return (end);
}

static char	*find_start(char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_skip_spaces(array, &i);
		if (array[i] == '1')
			break ;
		while (array[i] && array[i] != '\n')
			i++;
	}
	if (array[i] == '\0')
		return (panic("Map is empty"), NULL);
	return (array + i);
}

static int	nline_map(char *array)
{
	char	*start;
	char	*end;

	end = null_terminate(array);
	start = find_start(array);
	if (!start)
		return (1);
	start = ft_strchr(start, '\n');
	if (!start)
		return (panic("Invalid map"));
	while (start < end)
	{
		start--;
		while (my_strchr(" \t\r\v", *(start)))
			start--;
		if (*start == '\n')
			return (panic("Invalid map"));
		start = ft_strchr(start, '\n');
		start = ft_strchr(++start, '\n');
		if (!start)
			break ;
	}
	return (0);
}

t_map	*create_map(char *array, t_game *game)
{
	t_map	*map;

	if (nline_map(array))
		return (free(array), NULL);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (free(array), panic("Malloc error"), NULL);
	map->split = ft_split(array, '\n');
	free(array);
	if (!map->split)
		return (free(map), panic("Malloc error"), NULL);
	game->texture = init_texture(map->split);
	if (!game->texture)
		return (free_array(map->split), free(map), NULL);
	if (init_map(map->split, map))
		return (free(game->texture), free_array(map->split), free(map), NULL);
	return (map);
}
