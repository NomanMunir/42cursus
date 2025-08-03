/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:32:47 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/20 14:42:15 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	print_env(char **input, t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env_list;
	if (tmp == NULL)
		return (1);
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(tmp->value, 1);
		}
		tmp = tmp->next;
	}
	free_argv(input);
	if (shell->is_one_command)
		return (ft_free_tree(shell->cmd, shell), 0);
	return (panic(shell, 0, 1), 0);
}
