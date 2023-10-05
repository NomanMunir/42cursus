/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_files_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:34:53 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/05 10:54:15 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_open_here_doc_out(t_pipex *pipex)
{
	int	fd;

	pipex->fd_in = open("here_doc", O_RDONLY);
	check_error(pipex->fd_in == -1, "Create file error", 0, pipex);
	pipex->infile = "here_doc";
	fd = open(pipex->outfile, O_RDONLY);
	if (fd == -1)
	{
		pipex->fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, \
			0777);
		check_error(pipex->fd_out == -1, "Create file error", 1, pipex);
		close(pipex->fd_out);
	}
	close(fd);
	pipex->fd_out = open(pipex->outfile, O_WRONLY | O_APPEND, 0777);
	check_error(pipex->fd_out == -1, "Create file error", 1, pipex);
}

void	ft_open_files(t_pipex *pipex, char **argv)
{
	if (pipex->is_here_doc)
	{
		ft_open_here_doc_out(pipex);
		return ;
	}
	else if (pipex->is_error_file)
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

static void	init_reading(t_pipex *pipex, char **argv)
{
	char	*input;

	ft_putstr_fd("pipe heredoc> ", 1);
	input = get_next_line(0);
	check_error(input == NULL, "Empty here_doc", 1, pipex);
	while (ft_strcmp(argv[2], input) && input)
	{
		ft_putstr_fd(input, pipex->fd_in);
		free(input);
		ft_putstr_fd("pipe heredoc> ", 1);
		input = get_next_line(0);
		check_error(input == NULL, "here_doc exit", 1, pipex);
	}
	free(input);
}

void	init_here_doc(t_pipex *pipex, char **argv)
{
	if (pipex->is_here_doc)
	{
		pipex->fd_in = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		check_error(pipex->fd_in == -1, "Create file error", 0, pipex);
		init_reading(pipex, argv);
		close(pipex->fd_in);
	}
}
