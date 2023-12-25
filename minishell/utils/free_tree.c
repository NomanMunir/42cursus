/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:58:10 by abashir           #+#    #+#             */
/*   Updated: 2023/11/21 11:59:48 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_pipe(t_shell *shell, t_cmd *cmd)
{
	t_pipecmd	*pcmd;

	pcmd = (t_pipecmd *)cmd;
	ft_free_tree(pcmd->left, shell);
	ft_free_tree(pcmd->right, shell);
	free(pcmd);
}

void	free_hdoc(t_shell *shell, t_cmd *cmd)
{
	t_hdoc	*hcmd;

	hcmd = (t_hdoc *)cmd;
	free(hcmd->content);
	free(hcmd->delimiter);
	ft_free_tree(hcmd->cmd, shell);
	free(hcmd);
}

void	ft_free_tree(t_cmd *cmd, t_shell *shell)
{
	t_redircmd	*rcmd;
	t_execcmd	*ecmd;

	if (cmd->type == PIPE)
		free_pipe(shell, cmd);
	else if (cmd->type == REDIR)
	{
		rcmd = (t_redircmd *)cmd;
		ft_free_tree(rcmd->cmd, shell);
		free(rcmd);
	}
	else if (cmd->type == EXEC)
	{
		ecmd = (t_execcmd *)cmd;
		free(ecmd);
	}
	else if (cmd->type == HEREDOC)
		free_hdoc(shell, cmd);
}
