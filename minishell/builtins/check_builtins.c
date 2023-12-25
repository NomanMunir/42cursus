/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:33:28 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/21 11:08:23 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	is_builtin(char *input)
{
	if (ft_strcmp(input, "cd") == 0)
		return (true);
	else if (ft_strcmp(input, "export") == 0)
		return (true);
	else if (ft_strcmp(input, "unset") == 0)
		return (true);
	else if (ft_strcmp(input, "exit") == 0)
		return (true);
	else if (ft_strcmp(input, "pwd") == 0)
		return (true);
	else if (ft_strcmp(input, "echo") == 0)
		return (true);
	else if (ft_strcmp(input, "env") == 0)
		return (true);
	return (false);
}

static int	ft_unset_loop(t_shell *shell, char **av)
{
	int	i;

	i = 0;
	shell->g_exit_code = 0;
	while (av[++i])
	{
		if (ft_unset(shell, av[i]) == 1)
			shell->g_exit_code = 1;
	}
	free_argv(av);
	if (shell->is_one_command == 1)
		return (ft_free_tree(shell->cmd, shell), shell->g_exit_code);
	return (panic(shell, shell->g_exit_code, 1), shell->g_exit_code);
}

void	run_builtins(t_execcmd *ecmd, t_shell *shell)
{
	char	**av;

	av = ecmd->argv;
	if (ft_strcmp(*av, "cd") == 0)
		shell->g_exit_code = handle_cd(ecmd, shell);
	else if (ft_strcmp(*av, "pwd") == 0)
		shell->g_exit_code = ft_pwd(ecmd, shell);
	else if (ft_strcmp(*av, "echo") == 0)
		shell->g_exit_code = ft_echo(ecmd, shell);
	else if (ft_strcmp(*av, "unset") == 0)
		shell->g_exit_code = ft_unset_loop(shell, av);
	else if (ft_strcmp(*av, "export") == 0 && shell->is_one_command == 1)
		shell->g_exit_code = handle_export(av, shell);
	else if (ft_strcmp(*av, "export") == 0 && shell->is_one_command == 0)
		exit(handle_export(av, shell));
	else if (ft_strcmp(*av, "env") == 0)
		shell->g_exit_code = print_env(av, shell);
	else if (ft_strcmp(*av, "exit") == 0)
		ft_exit(ecmd, shell);
}
