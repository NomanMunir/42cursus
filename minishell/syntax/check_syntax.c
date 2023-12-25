/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:33:53 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/30 13:24:04 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_pipe(char *input, int *i)
{
	(*i)++;
	while (input[*i] == ' ' && input[*i])
		(*i)++;
	if (ft_strchr("|", input[*i]))
		return (syntax_error('|'), 1);
	if (input[*i] == '\0')
		return (syntax_error('|'), 1);
	if (ft_strchr("\"'", input[*i]))
	{
		if (is_quotes_closed(input, i))
			return (1);
	}
	return (0);
}

static int	check_redir(char *input, int *i)
{
	if (input[*i] == '<' || input[*i] == '>')
	{
		(*i)++;
		while (input[*i] == ' ' && input[*i])
			(*i)++;
		if (input[*i] == '\0')
			return (syntax_error(input[*i - 1]), 1);
		if (ft_strchr("\"'", input[*i]))
		{
			if (is_quotes_closed(input, i))
				return (1);
		}
		else if (ft_strchr("<&(|);>", input[*i]))
			return (syntax_error(input[*i]), 1);
	}
	return (0);
}

static int	check_redirs(char *input, int *i)
{
	if (!ft_strncmp(&input[*i], ">>", 2) || !ft_strncmp(&input[*i], "<<", 2))
	{
		*i += 2;
		while (input[*i] == ' ' && input[*i])
			(*i)++;
		if (input[*i] == '\0')
			return (syntax_error(input[*i - 1]), 1);
		if (ft_strchr("\"'", input[*i]))
		{
			if (is_quotes_closed(input, i))
				return (1);
		}
		else if (ft_strchr("<&(|);>", input[*i]))
			return (syntax_error(input[*i]), 1);
	}
	else
	{
		if (check_redir(input, i))
			return (1);
	}
	return (0);
}

static int	check_quotes(char *input, int *i)
{
	if (is_quotes_closed(input, i))
		return (1);
	return (0);
}

char	check_syntax(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] && input[i] == '|')
		{
			if (check_pipe(input, &i))
				return (1);
		}
		else if (input[i] && ft_strchr("<>", input[i]))
		{
			if (check_redirs(input, &i))
				return (1);
		}
		else if (ft_strchr("\"'", input[i]))
		{
			if (check_quotes(input, &i))
				return (1);
		}
		else
			i++;
	}
	return (0);
}
