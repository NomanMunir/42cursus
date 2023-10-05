/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:34:53 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/03 19:54:35 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_open_files(t_pipex *pipex, char **argv)
{
	if (pipex->is_error_file)
	{
		pipex->fd_in = open("error", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		check_error(pipex->fd_in == -1, "Create file error", 0, pipex);
		close(pipex->fd_in);
		pipex->fd_in = open("error", O_RDONLY);
		check_error(pipex->fd_in == -1, "Create file error", 0, pipex);
		pipex->infile = "error";
		perror("Open file error");
	}
	else
	{
		pipex->fd_in = open(argv[1], O_RDONLY);
		pipex->infile = argv[1];
	}
	pipex->fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	check_error(pipex->fd_out == -1, "Create file error", 1, pipex);
}
