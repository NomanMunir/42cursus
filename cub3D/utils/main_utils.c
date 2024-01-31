/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:26:45 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 14:25:30 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*read_file(char *av)
{
	int		fd;
	char	c[70001];
	char	*array;
	int		bytes;
	int		limiter;

	array = ft_strdup("");
	if (!array)
		return (panic("Malloc error"), NULL);
	fd = open(av, O_RDONLY);
	bytes = read(fd, c, 70000);
	limiter = bytes;
	while (bytes > 0)
	{
		c[bytes] = '\0';
		if (limiter >= 300000)
			return (free(array), close(fd), panic("File too big"), NULL);
		array = ft_joinfree(array, c);
		if (!array)
			return (panic("Malloc error"), NULL);
		bytes = read(fd, c, 70000);
		limiter += bytes;
	}
	return (close(fd), array);
}

int	check_input(int ac, char **av)
{
	if (ac != 2)
		return (panic("Wrong number of arguments"), 1);
	if (ft_strlen(av[1]) < 5 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub",
			4))
		return (panic("Wrong file extension"), 1);
	if (open_file(av[1]))
		return (panic("File not found / empty!"), 1);
	return (0);
}
