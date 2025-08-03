/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:59:40 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/30 10:54:05 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	redirs_token(char **s, int *ret)
{
	if (**s == '<')
	{
		(*s)++;
		if (**s == '<')
		{
			(*s)++;
			*ret = '-';
		}
		else
			*ret = '<';
	}
	else if (**s == '>')
	{
		(*s)++;
		if (**s == '>')
		{
			(*s)++;
			*ret = '+';
		}
		else
			*ret = '>';
	}
}

static void	quotes_token(char **str, char *es)
{
	while (*str < es)
	{
		(*str)++;
		if (*(*str - 1) == '"' || *(*str - 1) == '\'')
		{
			skip_char_token(str, es, *(*str - 1));
			if (**str != '\0')
				(*str)++;
		}
		if (**str == ' ' || **str == '\0' || ft_strchr("<>|", **str))
			break ;
	}
}

static void	else_token(char **s, char *es)
{
	while (*s < es && !ft_strchr(" \t\r\n\v<|>", **s))
	{
		if (**s == '\'')
		{
			(*s)++;
			skip_char_token(s, es, '\'');
		}
		else if (**s == '"')
		{
			(*s)++;
			skip_char_token(s, es, '"');
		}
		(*s)++;
	}
}

static int	token_cases(char **s, char *es, int *ret)
{
	*ret = **s;
	if (**s == 0)
		return (1);
	else if (**s == '|')
		(*s)++;
	else if (**s == '<' || **s == '>')
		redirs_token(s, ret);
	else
	{
		if (**s == '"' || **s == '\'')
			quotes_token(s, es);
		else
			else_token(s, es);
		*ret = 'a';
	}
	return (0);
}

int	gettoken(char **ps, char *es, char **q, char **eq)
{
	char	*s;
	int		ret;

	s = *ps;
	skip_spaces(&s, es);
	if (q)
		*q = s;
	if (token_cases(&s, es, &ret))
		return (ret);
	if (eq)
		*eq = s;
	skip_spaces(&s, es);
	*ps = s;
	return (ret);
}
