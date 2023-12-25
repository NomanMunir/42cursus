/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:58:43 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/26 16:04:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	update_export(t_shell *shell, char *key, char *value)
{
	char	*str;

	if (!value)
		return ;
	str = ft_strjoin(key, value);
	free(value);
	value = NULL;
	if (!str)
		return (ft_malloc_error(), panic(shell, 1, 1));
	ft_export(shell, str);
	free(str);
}

static int	ft_cd_home(t_shell *shell)
{
	char	*home;
	t_env	*tmp;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	home = NULL;
	tmp = find_env(shell->env_list, "HOME");
	if (tmp)
		home = tmp->value;
	if (home == NULL)
		return (free(pwd), ft_put_error("HOME not set", "cd", NULL), 1);
	if (chdir(home) == -1)
		return (free(pwd), ft_put_error(strerror(errno), "cd", NULL), 1);
	update_export(shell, "OLDPWD=", pwd);
	pwd = getcwd(NULL, 0);
	if (pwd)
		update_export(shell, "PWD=", pwd);
	return (0);
}

static int	ft_chdir(t_shell *shell, t_execcmd *ecmd)
{
	char	*oldpwd;

	oldpwd = NULL;
	if (find_env(shell->env_list, "OLDPWD"))
		oldpwd = find_env(shell->env_list, "OLDPWD")->value;
	if (oldpwd == NULL && ft_strncmp(ecmd->argv[1], "-", 1) == 0)
		return (ft_put_error("OLDPWD not set", "cd", NULL), 1);
	if (ft_strncmp(ecmd->argv[1], "-", 1) == 0)
	{
		if (chdir(oldpwd) == -1)
			return (ft_put_error(strerror(errno), "cd", NULL), 1);
		ft_putendl_fd(oldpwd, 1);
	}
	else if (chdir(ecmd->argv[1]) != 0)
		return (ft_put_error("No such file or directory", "cd ", ecmd->argv[1]),
			1);
	return (0);
}

static int	ft_cd(t_execcmd *ecmd, t_shell *shell)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (ft_chdir(shell, ecmd))
	{
		if (pwd)
			free(pwd);
		return (1);
	}
	if (pwd)
		update_export(shell, "OLDPWD=", pwd);
	pwd = getcwd(NULL, 0);
	if (pwd)
		update_export(shell, "PWD=", pwd);
	else
		return (ft_put_error("error retrieving current directory: getcwd: \
cannot access parent directories: No such file or directory", "cd",
				ecmd->argv[1]), 1);
	return (0);
}

int	handle_cd(t_execcmd *ecmd, t_shell *shell)
{
	if (ecmd->argv[1] == NULL || ft_strncmp(ecmd->argv[1], "~", 1) == 0)
	{
		if (ft_cd_home(shell))
		{
			if (shell->is_one_command)
				return (free_argv(ecmd->argv), ft_free_tree(shell->cmd, shell),
					1);
			return (free_argv(ecmd->argv), panic(shell, 1, 1), 1);
		}
		if (shell->is_one_command)
			return (free_argv(ecmd->argv), ft_free_tree(shell->cmd, shell), 0);
		return (free_argv(ecmd->argv), panic(shell, 0, 1), 0);
	}
	if (ft_cd(ecmd, shell))
	{
		if (shell->is_one_command)
			return (free_argv(ecmd->argv), ft_free_tree(shell->cmd, shell), 1);
		return (free_argv(ecmd->argv), panic(shell, 1, 1), 1);
	}
	if (shell->is_one_command)
		return (free_argv(ecmd->argv), ft_free_tree(shell->cmd, shell), 0);
	return (free_argv(ecmd->argv), panic(shell, 0, 1), 0);
}
