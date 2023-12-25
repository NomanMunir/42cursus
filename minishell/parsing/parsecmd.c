/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:29 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/30 14:39:57 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	set_args(t_parse_set *set, t_execcmd *cmd, char **ps, char *es)
{
	int	tok;

	tok = gettoken(ps, es, &set->q, &set->eq);
	if (tok == 0)
		return (1);
	if (tok != 'a')
		return (ft_put_error("syntax error", "unexpected token", set->q),
			parse_panic(set->shell, 1, 1, set->cmd), 1);
	cmd->argv[set->argc] = set->q;
	cmd->eargv[set->argc] = set->eq;
	(set->argc)++;
	if (set->argc >= MAXARGS)
	{
		ft_putendl_fd("too many args", 2);
		ft_free(set->shell->env);
		ft_clean_env(set->shell->env_list);
		ft_free_tree((t_cmd *)cmd, set->shell);
		if (set->shell->is_pipe)
			clean_cmd(set->shell, 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}

t_cmd	*parseexec(char **ps, char *es, t_shell *shell)
{
	t_execcmd	*cmd;
	t_cmd		*ret;
	t_parse_set	set;

	ret = execcmd();
	ft_memset(&set, 0, sizeof(set));
	set.shell = shell;
	cmd = (t_execcmd *)ret;
	ret = parseredirs(ret, ps, es, shell);
	while (!ft_peek(ps, es, "|"))
	{
		if (set_args(&set, cmd, ps, es))
			break ;
		ret = parseredirs(ret, ps, es, shell);
	}
	cmd->argv[set.argc] = 0;
	cmd->eargv[set.argc] = 0;
	return (ret);
}

t_cmd	*parsepipe(char **ps, char *es, t_shell *shell)
{
	t_cmd	*cmd;

	cmd = parseexec(ps, es, shell);
	if (ft_peek(ps, es, "|"))
	{
		add_cmd_list(shell, cmd);
		gettoken(ps, es, 0, 0);
		cmd = pipecmd(cmd, parsepipe(ps, es, shell));
		add_cmd_list(shell, cmd);
	}
	return (cmd);
}

t_cmd	*parseline(char **ps, char *es, t_shell *shell)
{
	t_cmd	*cmd;

	cmd = parsepipe(ps, es, shell);
	return (cmd);
}

t_cmd	*parsecmd(char *s, t_shell *shell)
{
	char	*es;
	t_cmd	*cmd;

	es = s + strlen(s);
	cmd = parseline(&s, es, shell);
	ft_peek(&s, es, "");
	if (s != es)
	{
		ft_put_error("syntax error", "unexpected token", s);
		parse_panic(shell, 1, 1, cmd);
	}
	clean_cmd(shell, 0);
	nulterminate(cmd);
	return (cmd);
}
