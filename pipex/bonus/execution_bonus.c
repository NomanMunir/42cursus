/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:36:30 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/05 10:37:14 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	change_fd(t_pipex *pipex, int i, int fd[2])
{
	if (i == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		close(pipex->fd_in);
	}
	if (pipex->cmds[i + 1] != NULL)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	else if (pipex->cmds[i + 1] == NULL)
	{
		dup2(pipex->fd_out, STDOUT_FILENO);
		close(pipex->fd_out);
	}
}

static void	open_pipe(t_pipex *pipex, int fd[2])
{
	if (pipe(fd) == -1)
		return (perror("pipe"), ft_free_pipex(pipex, false));
}

static void	ft_execve(t_pipex *pipex, char *cmd, int i, int fd[2])
{
	if (execve(cmd, pipex->args[i], pipex->envp) == -1)
	{
		close(STDOUT_FILENO);
		close(fd[1]);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Command not found", 2);
		ft_free_pipex(pipex, false);
		exit(EXIT_FAILURE);
	}
}

static void	ft_exec(t_pipex *pipex, int i, char *cmd)
{
	int	fd[2];
	int	pid;

	open_pipe(pipex, fd);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (perror("fork"), ft_free_pipex(pipex, false));
	}
	if (pid == 0)
	{
		close(fd[0]);
		change_fd(pipex, i, fd);
		ft_execve(pipex, cmd, i, fd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	process_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->cmds[++i])
		ft_exec(pipex, i, pipex->cmds[i]);
	while (i--)
		wait(NULL);
}
