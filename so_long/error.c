/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:36:47 by abashir           #+#    #+#             */
/*   Updated: 2023/09/10 13:18:42 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == 1)
		ft_putstr_fd("Map is not rectangular\n", 2);
	else if (error == 2)
		ft_putstr_fd("Map is not enclosed\n", 2);
	else if (error == 3)
		ft_putstr_fd("Wrong character in map\n", 2);
	else if (error == 4)
		ft_putstr_fd("Wrong number of arguments\n", 2);
	else if (error == 5)
		ft_putstr_fd("Wrong file extension\n", 2);
	else if (error == 6)
		ft_putstr_fd("File(s) not found\n", 2);
	else if (error == 7)
		ft_putstr_fd("Invalid map dimensions\n", 2);
	else if (error == 8)
		ft_putstr_fd("Map has invalid No# of exit/collectible or start\n", 2);
	else if (error == 9)
		ft_putstr_fd("Player can't reach collectible / exit\n", 2);
	else if (error == 10)
		ft_putstr_fd("File(s) empty/not found or corrupted\n", 2);
	else if (error == 11)
		ft_putstr_fd("Map is not valid\n", 2);
	exit(1);
}

void	handle_error_free(int error, char **map)
{
	ft_free_arr(map);
	handle_error(error);
}

static void	access_file(char *path)
{
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (fd < 0 || read(fd, &buf, 1) < 1)
		handle_error(10);
	close(fd);
}

void	is_file_valid(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		handle_error(4);
	while (argv[1][i] != '.' && argv[1][i])
		i++;
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0 \
	|| ft_strlen(argv[1] + i) > 4)
		handle_error(5);
	access_file(argv[1]);
	access_file(P_PATH);
	access_file(E_PATH);
	access_file(C_PATH);
	access_file(W_PATH);
	access_file(S_PATH);
}
