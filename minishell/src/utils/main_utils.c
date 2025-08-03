/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:07:32 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/07 17:20:52 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	is_one_cmd(char *input, t_shell *shell)
{
	int	i;
	int	c;

	i = 0;
	while (input[i])
	{
		while (input[i] && !ft_strchr("\"'<|>", input[i]))
			i++;
		if (input[i] == '\0')
			break ;
		if (ft_strchr("<|>", input[i]))
		{
			shell->is_one_command = 0;
			return ;
		}
		if (input[i] == '\'' || input[i] == '"')
		{
			c = input[i];
			while (input[++i] != c && input[i])
				;
		}
		i++;
	}
	shell->is_one_command = 1;
}

void	is_pipe_cmd(char *input, t_shell *shell)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!input)
		return ;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			c = input[i];
			while (input[++i] && input[i] != c)
				;
		}
		if (input[i] && input[i] == '|')
		{
			shell->is_pipe = true;
			return ;
		}
		i++;
	}
}

void	set_g_exit(t_shell *shell)
{
	if (!shell->is_pipe)
	{
		if (WTERMSIG(shell->g_exit_code) == 3)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
		else if (WTERMSIG(shell->g_exit_code) == 2)
			ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (WIFEXITED(shell->g_exit_code))
		shell->g_exit_code = WEXITSTATUS(shell->g_exit_code);
	else if (WIFSIGNALED(shell->g_exit_code))
		shell->g_exit_code = WTERMSIG(shell->g_exit_code) + 128;
}

void	close_fds(void)
{
	int	fd;

	fd = open("console", O_RDWR);
	while (fd >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break ;
		}
		fd = open("console", O_RDWR);
	}
}
