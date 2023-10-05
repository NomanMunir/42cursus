/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:33:50 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/05 10:54:24 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_free_3d(char ***str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			free(str[i][j]);
		free(str[i]);
	}
	free(str);
}

void	error_exit(char *str, int flag, t_pipex *pipex)
{
	if (pipex->args)
		ft_free_3d(pipex->args);
	if (pipex->path)
		ft_free(pipex->path);
	if (pipex->cmds)
		ft_free(pipex->cmds);
	if (flag == 1)
	{
		close(pipex->fd_in);
		close(pipex->fd_out);
		if (pipex->is_here_doc || pipex->is_error_file)
			unlink(pipex->infile);
		unlink(pipex->outfile);
	}
	if (pipex)
		free(pipex);
	perror(str);
	exit(EXIT_FAILURE);
}

void	check_error(int condition, char *str, int flag, t_pipex *pipex)
{
	if (condition && pipex)
		error_exit(str, flag, pipex);
	else if (condition && !pipex)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_free_pipex(t_pipex *pipex, bool flag)
{
	if (pipex->args)
		ft_free_3d(pipex->args);
	if (pipex->path)
		ft_free(pipex->path);
	if (pipex->cmds)
		ft_free(pipex->cmds);
	close(pipex->fd_in);
	close(pipex->fd_out);
	if (pipex->is_here_doc || pipex->is_error_file)
		unlink(pipex->infile);
	free(pipex);
	close(STDIN_FILENO);
	if (flag)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
