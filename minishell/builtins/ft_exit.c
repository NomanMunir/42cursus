/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:44:29 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/30 15:10:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	exit_exit(t_shell *shell, int flag, int e_code, t_execcmd *ecmd)
{
	char	**argv;

	argv = ecmd->argv;
	if (shell->is_one_command == 1)
		ft_putendl_fd("exit", 2);
	if (flag)
		ft_put_error("numeric argument required", "exit: ", argv[1]);
	return (free_argv(ecmd->argv), panic(shell, e_code, 1));
}

void	ft_exit(t_execcmd *ecmd, t_shell *shell)
{
	int		i;
	char	**argv;

	i = 0;
	argv = ecmd->argv;
	if (argv[2] != NULL && MAXARGS > 2)
	{
		shell->g_exit_code = 1;
		free_argv(ecmd->argv);
		if (shell->is_one_command == 1)
			return (ft_putendl_fd("exit", 2), ft_put_error("too many arguments",
					"exit", NULL), ft_free_tree(shell->cmd, shell));
		return (ft_put_error("too many arguments", "exit", NULL), panic(shell,
				1, 1));
	}
	if (argv[1])
	{
		shell->g_exit_code = my_atoll(argv[1], &i) % 256;
		if (i == 1)
			exit_exit(shell, 1, 255, ecmd);
	}
	else
		exit_exit(shell, 0, shell->g_exit_code, ecmd);
	exit_exit(shell, 0, shell->g_exit_code, ecmd);
}
