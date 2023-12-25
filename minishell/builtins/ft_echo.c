/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:33:28 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/04 16:20:30 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	check_nl(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

static int	exit_echo(t_shell *shell, t_execcmd *ecmd, bool flag)
{
	if (!flag)
		ft_putstr_fd("\n", 1);
	free_argv(ecmd->argv);
	if (shell->is_one_command)
		return (ft_free_tree(shell->cmd, shell), 0);
	return (panic(shell, 0, 1), 0);
}

int	ft_echo(t_execcmd *ecmd, t_shell *shell)
{
	char	**tmp;
	bool	flag;

	flag = false;
	tmp = ecmd->argv + 1;
	if (*tmp == NULL)
		return (ft_putstr_fd("\n", 1), exit_echo(shell, ecmd, true), 0);
	while (*tmp && ft_strncmp(*tmp, "-n", 2) == 0 && check_nl(*tmp))
	{
		tmp++;
		flag = true;
	}
	if (*tmp == NULL)
		return (exit_echo(shell, ecmd, true));
	ft_putstr_fd(*tmp, 1);
	tmp++;
	while (*tmp)
	{
		ft_putchar_fd(' ', 1);
		ft_putstr_fd(*tmp++, 1);
	}
	return (exit_echo(shell, ecmd, flag));
}
