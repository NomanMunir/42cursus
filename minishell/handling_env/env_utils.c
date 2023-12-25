/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:23:46 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/06 16:43:05 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*find_env(t_env *env_list, char *key)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	allocate_env(t_shell *shell, char **env)
{
	int	i;

	i = 0;
	if (MAXARGS < 2)
		return (ft_putendl_fd("MAXARGS must be at least 2", 2), exit(1));
	while (env[i])
		i++;
	shell->env = ft_calloc(sizeof(char *), i + 1);
	if (!shell->env)
		ft_malloc_error();
	i = 0;
	while (env[i])
	{
		shell->env[i] = ft_strdup(env[i]);
		if (!shell->env[i])
			ft_malloc_error();
		i++;
	}
	shell->env[i] = NULL;
}

t_env	*newlist(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	addfrontlst(char *key, char *value, t_env **env_list)
{
	t_env	*new;

	new = newlist(key, value);
	if (!new)
		return ;
	new->next = *env_list;
	*env_list = new;
}

void	set_shlvl(t_shell *shell)
{
	t_iterators	it;
	char		**env;

	ft_memset(&it, 0, sizeof(t_iterators));
	env = shell->env;
	while (*env)
	{
		if (ft_strncmp(*env, "SHLVL=", 6) == 0)
		{
			it.count = my_atoll(*env + 6, &it.error);
			if (it.error)
				ft_malloc_error();
			it.count++;
			it.tmp = ft_itoa(it.count);
			if (!it.tmp)
				ft_malloc_error();
			free(*env);
			*env = ft_strjoin("SHLVL=", it.tmp);
			free(it.tmp);
			if (!*env)
				ft_malloc_error();
			break ;
		}
		env++;
	}
}
