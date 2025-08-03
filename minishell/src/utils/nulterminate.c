/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nulterminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:38:06 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/07 16:33:38 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	nul_term_redir(t_cmd *cmd)
{
	t_redircmd	*rcmd;

	rcmd = (t_redircmd *)cmd;
	nulterminate(rcmd->cmd);
	*rcmd->efile = 0;
}

static void	nul_term_pipe(t_cmd *cmd)
{
	t_pipecmd	*pcmd;

	pcmd = (t_pipecmd *)cmd;
	nulterminate(pcmd->left);
	nulterminate(pcmd->right);
}

static void	nul_term_heredoc(t_cmd *cmd)
{
	t_hdoc	*heredoc;

	heredoc = (t_hdoc *)cmd;
	nulterminate(heredoc->cmd);
}

t_cmd	*nulterminate(t_cmd *cmd)
{
	int			i;
	t_execcmd	*ecmd;

	i = 0;
	if (cmd == 0)
		return (0);
	if (cmd->type == EXEC)
	{
		ecmd = (t_execcmd *)cmd;
		while (ecmd->argv[i])
			*ecmd->eargv[i++] = 0;
	}
	else if (cmd->type == REDIR)
		nul_term_redir(cmd);
	else if (cmd->type == PIPE)
		nul_term_pipe(cmd);
	else if (cmd->type == HEREDOC)
		nul_term_heredoc(cmd);
	return (cmd);
}
