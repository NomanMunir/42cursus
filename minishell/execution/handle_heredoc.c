/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:04:03 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/05 12:07:14 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_heredoc(t_cmd *cmd, t_shell *shell)
{
	t_hdoc	*heredoc;
	int		p[2];
	int		len;

	heredoc = (t_hdoc *)cmd;
	if (!heredoc->content)
		len = 0;
	else
		len = ft_strlen(heredoc->content);
	if (pipe(p) < 0)
		return (panic(shell, 1, 1));
	write(p[1], heredoc->content, len);
	close(p[1]);
	dup2(p[0], 0);
	close(p[0]);
	if (heredoc->cmd->type == HEREDOC)
		runcmd(((t_hdoc *)heredoc->cmd)->cmd, shell);
	runcmd(heredoc->cmd, shell);
}
