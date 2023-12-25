/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:56:58 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/26 16:02:50 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(t_execcmd *ecmd, t_shell *shell)
{
	char	*pwd;
	t_env	*env;

	pwd = NULL;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		env = find_env(shell->env_list, "PWD");
		if (env)
			pwd = ft_strdup(env->value);
	}
	ft_putendl_fd(pwd, 1);
	free_argv(ecmd->argv);
	if (shell->is_one_command)
		return (free(pwd), ft_free_tree(shell->cmd, shell), 0);
	return (free(pwd), panic(shell, 1, 1), 0);
}
