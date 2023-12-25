/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:33 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/30 13:36:56 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_redir(t_cmd *cmd, t_shell *shell)
{
	t_redircmd	*rcmd;
	int			fd;

	rcmd = (t_redircmd *)cmd;
	handle_quotes(&rcmd->file);
	close(rcmd->fd);
	fd = open(rcmd->file, rcmd->mode, 0777);
	if (fd == -1)
	{
		ft_put_error(strerror(errno), rcmd->file, NULL);
		panic(shell, 1, 1);
	}
	if (rcmd->cmd->type == REDIR && ((t_redircmd *)rcmd->cmd)->fd == 0
		&& rcmd->fd == 0)
		runcmd(((t_redircmd *)rcmd->cmd)->cmd, shell);
	else
		runcmd(rcmd->cmd, shell);
}
