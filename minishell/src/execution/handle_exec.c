/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:33 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/04 16:17:19 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	handle_quotes_expand(t_execcmd *ecmd, t_shell *shell)
{
	t_iterators	it;

	ft_memset(&it, 0, sizeof(t_iterators));
	while (ecmd->argv[it.i])
	{
		it.tmp = expand_env(ft_strdup(ecmd->argv[it.i]), shell);
		if (*it.tmp == '\0')
			it.i++;
		else
			ecmd->argv[it.j++] = split_expand(ecmd->argv[it.i++], shell);
		free(it.tmp);
	}
	while (ecmd->argv[it.j])
		ecmd->argv[it.j++] = NULL;
}

void	handle_exec(t_cmd *cmd, t_shell *shell)
{
	t_execcmd	*ecmd;

	ecmd = (t_execcmd *)cmd;
	if (ecmd->argv[0] == 0)
		panic(shell, 0, 1);
	handle_quotes_expand(ecmd, shell);
	if (ecmd->argv[0] == NULL)
		return (free_argv(ecmd->argv), panic(shell, 0, 1));
	if (is_builtin(ecmd->argv[0]))
		run_builtins(ecmd, shell);
	else
		ft_exec(ecmd, shell);
}
