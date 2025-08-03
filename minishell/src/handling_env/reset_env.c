/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:59:47 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/21 11:21:33 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	reset_env(t_shell *shell)
{
	t_env	*env;
	int		i;

	i = 0;
	env = shell->env_list;
	if (!env)
		return ;
	ft_free(shell->env);
	shell->env = ft_calloc(sizeof(char **), ft_lstsize(env) + 1);
	if (!shell->env)
		return (panic(shell, 1, 1));
	while (env)
	{
		if (!env->value)
			shell->env[i] = ft_strdup(env->key);
		else
		{
			shell->env[i] = ft_strjoin_3(env->key, "=", env->value);
			if (!shell->env[i])
				return (panic(shell, 1, 1));
		}
		i++;
		env = env->next;
	}
	shell->env[i] = NULL;
}
