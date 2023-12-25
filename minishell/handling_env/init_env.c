/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:19:54 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/13 18:04:44 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_env(t_shell *shell)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	i = 0;
	if (!shell->env)
		return ;
	while (shell->env[i])
	{
		j = 0;
		while (shell->env[i][j] != '=')
			j++;
		key = ft_substr(shell->env[i], 0, j);
		value = ft_substr(shell->env[i], j + 1, ft_strlen(shell->env[i]) - j);
		addfrontlst(key, value, &shell->env_list);
		i++;
	}
}
