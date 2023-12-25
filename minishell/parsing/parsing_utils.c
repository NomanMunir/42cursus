/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:50:29 by abashir           #+#    #+#             */
/*   Updated: 2023/12/10 08:09:23 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_token(char **ps, char *es, t_parse_set *set, t_cmd *cmd)
{
	set->tok = gettoken(ps, es, 0, 0);
	if (gettoken(ps, es, &set->q, &set->eq) != 'a')
	{
		ft_put_error("syntax error", "missing file for redirection", set->q);
		if (set->shell->is_pipe)
			clean_cmd(set->shell, 1);
		parse_panic(set->shell, 1, 1, cmd);
	}
}

void	clean_cmd(t_shell *shell, bool flag)
{
	t_cmd_list	*tmp;
	t_cmd_list	*tmp2;

	tmp = shell->cmd_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (flag)
			ft_free_tree(tmp->cmd, shell);
		free(tmp);
		tmp = tmp2;
	}
}

void	add_cmd_list(t_shell *shell, t_cmd *cmd)
{
	t_cmd_list	*new;
	t_cmd_list	*tmp;

	new = NULL;
	tmp = NULL;
	new = malloc(sizeof(t_cmd_list));
	if (!new)
		return ;
	new->cmd = cmd;
	new->next = NULL;
	if (!shell->cmd_list)
		shell->cmd_list = new;
	else
	{
		tmp = shell->cmd_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	set_heredoc(bool *flag, char **content, char **tmp)
{
	*flag = false;
	*content = NULL;
	*tmp = NULL;
	signal(SIGINT, sig_handler_hdoc);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_find_next(char **ps, t_parse_set *set)
{
	int		i;
	char	*str;
	char	*filename;

	i = 0;
	str = *ps;
	while (str[i] && str[i] != '|')
	{
		if (ft_strncmp(&str[i], "<<", 2) == 0)
		{
			*ps = str + i;
			break ;
		}
		i++;
	}
	if (str[i] == '|')
		*ps = ft_strchr(set->q, '|');
	else if (str[i] == '\0' && !set->shell->is_pipe)
	{
		filename = ft_strndup(set->q, set->eq - set->q);
		ft_put_error(strerror(errno), filename, NULL);
		free(filename);
		clean_cmd(set->shell, 1);
		parse_panic(set->shell, 1, 1, set->cmd);
	}
}
