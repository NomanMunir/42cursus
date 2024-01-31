/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:43:52 by abashir           #+#    #+#             */
/*   Updated: 2024/01/29 16:21:27 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	open_file(char *path)
{
	int		fd;
	char	buf;
	int		byte;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	byte = read(fd, &buf, 1);
	while (byte != 0)
	{
		if (!my_strchr(" \t\r\v\f\n", buf))
			return (close(fd), 0);
		byte = read(fd, &buf, 1);
	}
	if (byte == 0)
		return (close(fd), 1);
	return (close(fd), 0);
}

char	*ft_joinfree(char *s1, char *buf)
{
	int		i;
	char	*joined_str;
	int		size;

	size = ft_strlen(s1) + ft_strlen(buf) + 1;
	i = -1;
	joined_str = ft_calloc(sizeof(char) * size, 1);
	if (joined_str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		joined_str[i] = s1[i];
	while (*buf != '\0')
		joined_str[i++] = *buf++;
	joined_str[i] = '\0';
	return (free(s1), joined_str);
}

void	ft_skip_spaces(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
}

int	find_ptr(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[i])
	{
		j = 0;
		ft_skip_spaces(split[i], &j);
		if (split[i][j] == '1' || split[i][j] == '0')
			break ;
		i++;
	}
	if (split[i] == NULL)
		return (0);
	return (i);
}

int	check_lines(char **split)
{
	int	i;
	int	count;
	int	j;

	count = 0;
	i = 0;
	while (split[i])
	{
		j = 0;
		ft_skip_spaces(split[i], &j);
		if (split[i][j] != '0' && split[i][j] != '1' && split[i][j] != '\0')
			count++;
		else if (split[i][j] == '1' || split[i][j] == '0')
		{
			split += i;
			break ;
		}
		i++;
	}
	return (count);
}
