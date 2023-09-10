/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/09/10 13:25:58 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	contain_invalid(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size.x)
	{
		j = 0;
		while (j < game->size.y)
		{
			if (game->plot[i][j] != '0' && game->plot[i][j] != '1' && \
			game->plot[i][j] != 'C' && game->plot[i][j] != 'E' && \
			game->plot[i][j] != 'P')
				handle_error_free(3, game->plot);
			j++;
		}
		i++;
	}
}

int	count_row(char *argv)
{
	char	*line;
	int		row;
	int		fd;

	row = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (row);
}

char	**create_map(char *argv, t_map *game)
{
	char	*line;
	int		i;
	char	**array;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	game->size.x = count_row(argv);
	game->plot = malloc(sizeof(char *) * (game->size.x + 1));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (line[0] == '\n')
			return (ft_free_arr(game->plot), free(line), NULL);
		array = ft_split(line, '\n');
		game->plot[i++] = array[0];
		free(array);
		free(line);
		line = get_next_line(fd);
	}
	game->plot[i] = NULL;
	close(fd);
	game->size.y = ft_strlen(game->plot[0]);
	return (game->plot);
}
