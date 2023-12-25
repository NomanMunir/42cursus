/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:27:39 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/15 13:34:25 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	ft_valid_key(char *key)
{
	int	i;

	i = 0;
	if (ft_isdigit(key[0]))
		return (false);
	while (key[i])
	{
		if (ft_isalnum(key[i]) == 0 && key[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

static void	free_tmp(t_env *tmp)
{
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}

int	ft_unset(t_shell *shell, char *key)
{
	t_env		*tmp;
	t_env		*prev;

	tmp = shell->env_list;
	prev = NULL;
	if (ft_valid_key(key) == false)
		return (ft_put_error("not a valid identifier", "unset: ", key), 1);
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
		{
			if (prev == NULL)
				shell->env_list = tmp->next;
			else
				prev->next = tmp->next;
			return (free_tmp(tmp), 0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (0);
}
