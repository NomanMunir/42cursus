/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:22:44 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 14:00:43 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int			g_signum = 0;

void	set_fork(t_shell *shell, char *input)
{
	pid_t	pid;
	int		status;

	if (shell->is_builtins && shell->is_one_command)
	{
		shell->is_forked = false;
		shell->cmd = parsecmd(input, shell);
		runcmd(shell->cmd, shell);
	}
	else
	{
		shell->is_forked = true;
		pid = get_fork();
		if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			iterm_change(true);
			shell->cmd = parsecmd(input, shell);
			runcmd(shell->cmd, shell);
		}
		waitpid(pid, &status, 0);
		shell->g_exit_code = status;
		set_g_exit(shell);
	}
}

void	reset_var(t_shell *shell)
{
	g_signum = 0;
	config_signals();
	shell->is_pipe = false;
	shell->is_builtins = false;
	shell->is_forked = false;
}

static void	shell_loop(t_shell *shell)
{
	char	*input;

	input = NULL;
	while (1)
	{
		reset_var(shell);
		input = check_input(readline(PROMPT), shell);
		if (input == NULL)
			return (ft_putstr_fd("exit\n", 1), ft_free_success(shell,
					shell->g_exit_code, true));
		if (input[0] == '\0')
		{
			free(shell->input);
			continue ;
		}
		is_one_cmd(input, shell);
		is_pipe_cmd(input, shell);
		if (g_signum == 2 && !shell->is_forked)
			shell->g_exit_code = 1;
		set_fork(shell, input);
		free(shell->input);
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)av;
	if (ac != 1)
		return (ft_putendl_fd("minishell: too many arguments", 2), 1);
	ft_memset(&shell, 0, sizeof(t_shell));
	allocate_env(&shell, env);
	set_shlvl(&shell);
	close_fds();
	init_env(&shell);
	shell_loop(&shell);
	return (0);
}
