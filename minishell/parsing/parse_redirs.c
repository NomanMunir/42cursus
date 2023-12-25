/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:30:14 by abashir           #+#    #+#             */
/*   Updated: 2023/11/30 14:41:11 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	open_file(t_parse_set *set, int mode)
{
	int	fd;

	fd = 0;
	set->filename = ft_strndup(set->q, set->eq - set->q);
	handle_quotes(&set->filename);
	if (mode == O_RDONLY)
		fd = open(set->filename, mode);
	else
		fd = open(set->filename, mode, 0777);
	if (fd == -1)
	{
		set->error = true;
		return (free(set->filename), 1);
	}
	if (fd != -1)
		close(fd);
	free(set->filename);
	return (0);
}

static int	open_file_last_redir(t_parse_set *set)
{
	int	fd;

	fd = 0;
	set->filename = ft_strndup(set->q, set->eq - set->q);
	handle_quotes(&set->filename);
	if (ft_strcmp(set->t, ">>") == 0)
		fd = open(set->filename, O_CREAT | O_WRONLY | O_APPEND, 0777);
	else if (ft_strcmp(set->t, "<") == 0)
		fd = open(set->filename, O_RDONLY);
	else if (ft_strcmp(set->t, ">") == 0)
		fd = open(set->filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
	{
		set->error = true;
		return (free(set->filename), 1);
	}
	free(set->filename);
	if (fd != -1)
		close(fd);
	return (0);
}

static int	ft_find_last_redirection(char **ps, char *es, t_parse_set *set)
{
	while (ft_peek(ps, es, set->t))
	{
		if (ft_strncmp(*ps, "<<", 2) == 0)
			return (1);
		gettoken(ps, es, 0, 0);
		if (gettoken(ps, es, &set->q, &set->eq) != 'a')
			return (ft_put_error("syntax error", "missing file for redirection",
					set->q), parse_panic(set->shell, 1, 1, set->cmd), 1);
		if (!ft_strcmp(set->t, ">>") || !ft_strcmp(set->t, "<")
			|| !ft_strcmp(set->t, ">"))
		{
			if (open_file_last_redir(set))
				return (ft_find_next(ps, set), 0);
		}
		else if (set->eq != NULL)
		{
			if (ft_peek(ps, es, set->t))
				ft_find_last_redirection(ps, es, set);
		}
	}
	return (0);
}

static int	ft_create_redircmd(t_parse_set *set, char **ps, char *es)
{
	if (set->tok == '<')
	{
		set->t = "<";
		set->mode = O_RDONLY;
		set->fd = 0;
	}
	else if (set->tok == '>')
	{
		set->t = ">";
		set->mode = O_CREAT | O_WRONLY | O_TRUNC;
		set->fd = 1;
	}
	else if (set->tok == '+')
	{
		set->t = ">>";
		set->mode = O_WRONLY | O_CREAT | O_APPEND;
		set->fd = 1;
	}
	if (open_file(set, set->mode))
		return (ft_find_next(ps, set), 0);
	if (ft_find_last_redirection(ps, es, set))
		return (1);
	return (0);
}

t_cmd	*parseredirs(t_cmd *cmd, char **ps, char *es, t_shell *shell)
{
	t_parse_set	set;

	ft_memset(&set, 0, sizeof(set));
	set.error = false;
	set.shell = shell;
	while (ft_peek(ps, es, "<>"))
	{
		set.cmd = cmd;
		check_token(ps, es, &set, cmd);
		if ((set.tok == '<' || set.tok == '>' || set.tok == '+') && !set.error)
		{
			if (ft_create_redircmd(&set, ps, es) == 0)
				cmd = redircmd(cmd, set);
		}
		else if (set.tok == '-')
		{
			set.content = parse_heredoc(ft_strndup(set.q, set.eq - set.q),
					shell, &set);
			if (ft_find_last_heredoc(ps, es, &set) == 0)
				cmd = heredoccmd(cmd, set.content, ft_strndup(set.q, set.eq
							- set.q));
		}
	}
	return (cmd);
}
