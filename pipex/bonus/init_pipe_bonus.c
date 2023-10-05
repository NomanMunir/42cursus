/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:34:14 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/03 19:55:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_find_path(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = -1;
	while (pipex->envp[++i])
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_substr(pipex->envp[i], 5, ft_strlen(pipex->envp[i]) - 5);
			check_error(!tmp, "malloc", 1, pipex);
			pipex->path = ft_split(tmp, ':');
			free(tmp);
			check_error(!pipex->path, "malloc", 1, pipex);
			return ;
		}
	}
	check_error(!pipex->path, "Path not found", 1, pipex);
}

static bool	check_access(char *cmd)
{
	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
		return (true);
	return (false);
}

static void	is_valid_cmd(t_pipex *pipex, int j)
{
	int		i;
	char	*cmd;

	i = -1;
	while (pipex->path[++i])
	{
		if (pipex->args[j][0][0] == '/' && check_access(pipex->args[j][0]))
		{
			pipex->cmds[j] = ft_strdup(pipex->args[j][0]);
			check_error(!pipex->cmds[j], "malloc", 1, pipex);
			break ;
		}
		cmd = ft_strjoin_3(pipex->path[i], "/", pipex->args[j][0]);
		check_error(!cmd, "malloc", 1, pipex);
		if (check_access(cmd))
		{
			pipex->cmds[j] = ft_strdup(cmd);
			free(cmd);
			check_error(!pipex->cmds[j], "malloc", 1, pipex);
			break ;
		}
		free(cmd);
	}
	if (!pipex->cmds[j])
		pipex->cmds[j] = ft_strdup(pipex->args[j][0]);
}

void	ft_set_path(t_pipex *pipex)
{
	int	j;

	j = -1;
	pipex->cmds = ft_calloc((pipex->cmd_count + 1), sizeof(char *));
	check_error(!pipex->cmds, "malloc", 1, pipex);
	while (pipex->args[++j])
		is_valid_cmd(pipex, j);
	pipex->cmds[j] = NULL;
}

void	ft_init_pipe(t_pipex *pipex, char **envp)
{
	pipex->envp = envp;
	ft_find_path(pipex);
	ft_set_path(pipex);
}
