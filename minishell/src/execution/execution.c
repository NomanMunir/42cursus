/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:30:49 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 14:04:34 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_file_dir_access(char *path)
{
	int	dir_fd;

	dir_fd = open(path, O_RDONLY | O_DIRECTORY);
	if (dir_fd != -1)
	{
		close(dir_fd);
		return (1);
	}
	else
	{
		if (access(path, F_OK) != 0)
		{
			if (errno == ENOENT)
				return (2);
			else if (errno == EPERM)
				return (4);
			else
				return (3);
		}
	}
	return (0);
}

static char	*check_abs_path(t_execcmd *ecmd, t_shell *shell)
{
	int	dir_result;

	dir_result = check_file_dir_access(ecmd->argv[0]);
	if (dir_result == 1)
		return (ft_put_error(strerror(EISDIR), ecmd->argv[0], NULL),
			free_argv(ecmd->argv), panic(shell, 126, 1), NULL);
	else if (dir_result == 3)
		return (ft_put_error(strerror(EACCES), ecmd->argv[0], NULL),
			free_argv(ecmd->argv), panic(shell, 126, 1), NULL);
	else if (dir_result == 2)
		return (ft_put_error(strerror(ENOENT), ecmd->argv[0], NULL),
			free_argv(ecmd->argv), panic(shell, 127, 1), NULL);
	else if (dir_result == 4)
		return (ft_put_error(strerror(EPERM), ecmd->argv[0], NULL),
			free_argv(ecmd->argv), panic(shell, 126, 1), NULL);
	return (ft_strdup(ecmd->argv[0]));
}

void	ft_exec(t_execcmd *ecmd, t_shell *shell)
{
	char	*cmd_path;

	cmd_path = NULL;
	if (ft_strchr(ecmd->argv[0], '/'))
		cmd_path = check_abs_path(ecmd, shell);
	else
		cmd_path = get_cmd_path(shell, ecmd->argv);
	if (!cmd_path)
		return (free_argv(ecmd->argv), panic(shell, 127, 1));
	if (execve(cmd_path, ecmd->argv, shell->env) == -1)
		return (ft_put_error(strerror(errno), ecmd->argv[0], NULL),
			free_argv(ecmd->argv), free(cmd_path), panic(shell, 126, 1));
}

void	runcmd(t_cmd *cmd, t_shell *shell)
{
	if (cmd == 0)
		panic(shell, 1, 1);
	if (cmd->type == EXEC)
		handle_exec(cmd, shell);
	else if (cmd->type == PIPE)
		handle_pipe(cmd, shell);
	else if (cmd->type == HEREDOC)
		handle_heredoc(cmd, shell);
	else if (cmd->type == REDIR)
		handle_redir(cmd, shell);
	else
		panic(shell, 1, 0);
	if (shell->is_forked == 1)
	{
		set_g_exit(shell);
		exit(shell->g_exit_code);
	}
}
