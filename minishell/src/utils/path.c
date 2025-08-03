/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:11:41 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/29 17:57:21 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_cmd_path(t_shell *shell, char **cmds)
{
	int		i;
	t_env	*tmp;
	char	**path;
	char	*str;

	i = -1;
	str = NULL;
	if (cmds[0][0] == '\0')
		return (ft_put_error("command not found", NULL, *cmds), NULL);
	tmp = find_env(shell->env_list, "PATH");
	if (!tmp)
		return (ft_put_error(strerror(ENOENT), NULL, *cmds), free_argv(cmds),
			panic(shell, 127, 1), NULL);
	path = ft_split(tmp->value, ':');
	if (!path)
		return (ft_malloc_error(), NULL);
	while (path[++i])
	{
		str = ft_strjoin_3(path[i], "/", *cmds);
		if (check_access(str))
			return (ft_free(path), str);
		free(str);
	}
	return (ft_free(path), ft_put_error("command not found", NULL, *cmds),
		NULL);
}
