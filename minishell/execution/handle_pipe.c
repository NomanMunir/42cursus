/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:00:05 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 13:59:52 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	handle_left_child(int *pid, int *p, t_pipecmd *pcmd, t_shell *shell)
{
	*pid = get_fork();
	if (*pid == 0)
	{
		close(1);
		dup(p[1]);
		close(p[0]);
		close(p[1]);
		runcmd(pcmd->left, shell);
	}
}

static void	handle_right_child(int *pid, int *p, t_pipecmd *pcmd,
		t_shell *shell)
{
	*pid = get_fork();
	if (*pid == 0)
	{
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		runcmd(pcmd->right, shell);
	}
}

void	handle_pipe(t_cmd *cmd, t_shell *shell)
{
	t_pipecmd	*pcmd;
	int			left_status;
	int			right_status;
	int			p[2];
	int			pid[2];

	left_status = 0;
	right_status = 0;
	pcmd = (t_pipecmd *)cmd;
	if (pipe(p) < 0)
		panic(shell, 1, 1);
	signal(SIGPIPE, sigpipe_handler);
	handle_left_child(&pid[0], p, pcmd, shell);
	handle_right_child(&pid[1], p, pcmd, shell);
	close(p[0]);
	close(p[1]);
	panic(shell, 0, 0);
	waitpid(pid[0], &left_status, 0);
	waitpid(pid[1], &right_status, 0);
	if (WTERMSIG(left_status) == 3 || WTERMSIG(right_status) == 3)
		ft_putendl_fd("", STDERR_FILENO);
	// else if ((WTERMSIG(left_status) == 2))
	// {
	// 	ft_putnbr_fd(g_signum, 2);
	// 	ft_putstr_fd("\n", STDERR_FILENO);
	// }
	// else if (WTERMSIG(right_status) == 2)
	// 	ft_putstr_fd("\n", STDERR_FILENO);
	shell->g_exit_code = right_status;
}
