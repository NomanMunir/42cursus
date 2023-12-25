/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:17:53 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/06 15:16:40 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_success(t_shell *shell, int e_code, bool is_exit)
{
	if (shell->env)
		ft_free(shell->env);
	if (shell->env_list)
		ft_clean_env(shell->env_list);
	shell = NULL;
	if (g_signum == 2)
		exit(1);
	if (is_exit)
		exit(e_code);
}

void	ft_clean_env(t_env *env_list)
{
	t_env	*tmp;

	while (env_list)
	{
		tmp = env_list->next;
		if (env_list->key)
			free(env_list->key);
		if (env_list->value)
			free(env_list->value);
		free(env_list);
		env_list = tmp;
	}
	env_list = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	argv = NULL;
}
