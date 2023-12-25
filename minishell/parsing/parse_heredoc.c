/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:28:51 by abashir           #+#    #+#             */
/*   Updated: 2023/12/07 14:17:33 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_find_last_heredoc(char **ps, char *es, t_parse_set *set)
{
	while (ft_peek(ps, es, "<<"))
	{
		free(set->content);
		if (ft_strncmp(*ps, "<<", 2))
			return (1);
		if (ft_peek(ps, es, "<<"))
			return (1);
		gettoken(ps, es, 0, 0);
		if (gettoken(ps, es, &set->q, &set->eq) != 'a')
			return (ft_put_error("syntax error",
					"missing delimeter for heredoc", set->q),
				parse_panic(set->shell, 1, 1, set->cmd), 1);
		else
		{
			set->content = parse_heredoc(ft_strndup(set->q, set->eq - set->q),
					set->shell, set);
			if (ft_peek(ps, es, "<<"))
				ft_find_last_heredoc(ps, es, set);
		}
	}
	return (0);
}

static void	free_expand(char **content, t_shell *shell)
{
	char	*tmp;

	tmp = *content;
	*content = split_expand(*content, shell);
	free(tmp);
}

static int	check_heredoc(char **content, bool flag, char *dlm, t_shell *shell)
{
	char	*tmp_content;

	tmp_content = ft_strdup(*content);
	handle_quotes(&tmp_content);
	if (flag)
	{
		if (ft_strcmp(dlm, *content) == 0)
			return (free(tmp_content), 1);
		else if (ft_strcmp(dlm, tmp_content) != 0)
			free_expand(content, shell);
	}
	else
	{
		if (ft_strcmp(dlm, *content) == 0)
			return (free(tmp_content), 1);
		else
			free_expand(content, shell);
	}
	free(tmp_content);
	return (0);
}

char	*parse_heredoc(char *dlm, t_shell *shell, t_parse_set *set)
{
	char	*content;
	char	*tmp;
	bool	flag;

	iterm_change(false);
	set_heredoc(&flag, &content, &tmp);
	if (ft_strchr(dlm, '"') && handle_quotes(&dlm))
		flag = true;
	while (1)
	{
		ft_putstr_fd("> ", 1);
		content = get_next_line(0);
		if (g_signum == SIGINT)
			return (free(dlm), free(content), free(tmp), parse_panic(shell, 1,
					1, set->cmd), NULL);
		if (content == 0 || *content == 0)
			return (free(dlm), free(content), tmp);
		content[ft_strlen(content) - 1] = '\0';
		if (check_heredoc(&content, flag, dlm, shell))
			return (free(dlm), free(content), tmp);
		content = ft_strjoin_gnl(content, "\n");
		tmp = ft_strjoin_gnl(tmp, content);
		free(content);
	}
	return (free(dlm), tmp);
}
