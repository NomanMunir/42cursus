/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:38 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 10:20:08 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_sort_export(t_env *env_list)
{
	t_env	*tmp;
	t_env	*tmp2;
	char	*tmp_key;
	char	*tmp_value;

	tmp = env_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strncmp(tmp->key, tmp2->key, ft_strlen(tmp2->key)) > 0)
			{
				tmp_key = tmp->key;
				tmp_value = tmp->value;
				tmp->key = tmp2->key;
				tmp->value = tmp2->value;
				tmp2->key = tmp_key;
				tmp2->value = tmp_value;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (env_list);
}

void	ft_print_export(t_env *env_list)
{
	env_list = ft_sort_export(env_list);
	while (env_list)
	{
		if (env_list->value)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(env_list->key, 1);
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env_list->value, 1);
			ft_putstr_fd("\"\n", 1);
		}
		else
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(env_list->key, 1);
			ft_putstr_fd("\n", 1);
		}
		env_list = env_list->next;
	}
}

void	ft_set_export(char *input, t_shell *shell, int i, int p)
{
	t_env	*tmp;
	char	*set[2];

	set[1] = NULL;
	if (input[i] == '\0')
		set[0] = ft_strdup(input);
	else
	{
		set[0] = ft_substr(input, 0, i);
		set[1] = ft_substr(input, i + 1 + p, ft_strlen(input) - i);
	}
	tmp = find_env(shell->env_list, set[0]);
	if (tmp)
	{
		free(set[0]);
		if (set[1] == NULL)
			set[1] = tmp->value;
		else
		{
			free(tmp->value);
			tmp->value = set[1];
		}
	}
	else
		addfrontlst(set[0], set[1], &shell->env_list);
}
