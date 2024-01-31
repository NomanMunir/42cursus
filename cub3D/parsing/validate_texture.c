/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:04:22 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/30 13:53:48 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*fill_texture(char *key, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (ft_strncmp(key, str, ft_strlen(key)) == 0)
	{
		str += ft_strlen(key);
		ft_skip_spaces(str, &i);
		if (str[i] == '\0')
			return (panic("Missing texture path"), NULL);
		tmp = str + i;
		return (tmp);
	}
	return (NULL);
}

static int	find_texture(char *str, t_texture *texture)
{
	int	i;

	i = 0;
	ft_skip_spaces(str, &i);
	str += i;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '1' || str[0] == '0')
		return (2);
	if (!my_strchr("NSEWFC", str[0]))
		return (panic("Wrong texture format"));
	if (fill_texture("NO ", str))
		texture->no = fill_texture("NO ", str);
	else if (fill_texture("SO ", str))
		texture->so = fill_texture("SO ", str);
	else if (fill_texture("WE ", str))
		texture->we = fill_texture("WE ", str);
	else if (fill_texture("EA ", str))
		texture->ea = fill_texture("EA ", str);
	else if (fill_texture("F ", str))
		texture->f = fill_texture("F ", str);
	else if (fill_texture("C ", str))
		texture->c = fill_texture("C ", str);
	return (0);
}

static int	validate_colors(char *color, int *color_int)
{
	int	count;
	int	num;

	count = 0;
	while (1)
	{
		num = my_atoi(color);
		if (num < 0 || num > 255)
			return (1);
		color_int[count] = num;
		color = ft_strchr(color, ',');
		if (!color++)
			break ;
		count++;
		if (count > 2)
			return (1);
	}
	if (count != 2)
		return (1);
	return (0);
}

static int	validate_texture(t_texture *texture)
{
	if (ft_strlen(texture->no) < 5 || ft_strncmp(texture->no
			+ ft_strlen(texture->no) - 4, ".xpm", 4)
		|| ft_strlen(texture->so) < 5 || ft_strncmp(texture->so
			+ ft_strlen(texture->so) - 4, ".xpm", 4)
		|| ft_strlen(texture->we) < 5 || ft_strncmp(texture->we
			+ ft_strlen(texture->we) - 4, ".xpm", 4)
		|| ft_strlen(texture->ea) < 5 || ft_strncmp(texture->ea
			+ ft_strlen(texture->ea) - 4, ".xpm", 4))
		return (panic("Wrong file extension"));
	if (open_file(texture->no) || open_file(texture->so)
		|| open_file(texture->we) || open_file(texture->ea))
		return (panic("Texture file not found/ empty"));
	if (validate_colors(texture->f, texture->floor)
		|| validate_colors(texture->c, texture->ceiling))
		return (panic("Wrong color format"));
	return (0);
}

t_texture	*init_texture(char **split)
{
	int			i;
	int			count;
	t_texture	*texture;

	i = -1;
	count = check_lines(split);
	if (count != 6)
		return (panic("Missing / Duplicate information in the map."), NULL);
	texture = ft_calloc(sizeof(t_texture), 1);
	if (!texture)
		return (panic("Malloc error"), NULL);
	while (split[++i])
	{
		if (find_texture(split[i], texture) == 1)
			return (free(texture), NULL);
		else if (find_texture(split[i], texture) == 2)
			break ;
	}
	if (texture->no == NULL || texture->so == NULL || texture->we == NULL
		|| texture->ea == NULL || texture->f == NULL || texture->c == NULL)
		return (panic("Invalid Texture"), free(texture), NULL);
	if (validate_texture(texture))
		return (free(texture), NULL);
	return (texture);
}
