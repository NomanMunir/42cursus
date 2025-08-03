/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:42:14 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 08:15:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_cmd	*heredoccmd(t_cmd *subcmd, char *content, char *delimiter)
{
	t_hdoc	*heredoc;

	heredoc = ft_calloc(sizeof(*heredoc), 1);
	if (!heredoc)
		ft_malloc_error();
	heredoc->type = HEREDOC;
	heredoc->content = content;
	heredoc->delimiter = delimiter;
	heredoc->cmd = subcmd;
	return ((t_cmd *)heredoc);
}

t_cmd	*redircmd(t_cmd *subcmd, t_parse_set set)
{
	t_redircmd	*cmd;

	cmd = ft_calloc(sizeof(*cmd), 1);
	if (!cmd)
		ft_malloc_error();
	cmd->type = REDIR;
	cmd->cmd = subcmd;
	cmd->file = set.q;
	cmd->efile = set.eq;
	cmd->mode = set.mode;
	cmd->fd = set.fd;
	return ((t_cmd *)cmd);
}

t_cmd	*execcmd(void)
{
	t_execcmd	*cmd;

	cmd = ft_calloc(sizeof(*cmd), 1);
	if (!cmd)
		ft_malloc_error();
	cmd->type = EXEC;
	return ((t_cmd *)cmd);
}

t_cmd	*pipecmd(t_cmd *left, t_cmd *right)
{
	t_pipecmd	*cmd;

	cmd = ft_calloc(sizeof(*cmd), 1);
	if (!cmd)
		ft_malloc_error();
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}
