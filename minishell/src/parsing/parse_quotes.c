/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:12:18 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/29 11:40:49 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	skip_char(t_iterators *it, char c, int flag)
{
	it->i++;
	while (it->src[it->i] && it->src[it->i] != c)
	{
		if (it->src[it->i] == '$' && flag)
			it->flag = false;
		it->dest[it->j] = it->src[it->i];
		it->i++;
		it->j++;
	}
	if (!it->src[it->i])
		return (1);
	it->i++;
	return (0);
}

int	set_iterators(t_iterators *it, char *input)
{
	if (!input)
		return (1);
	it->i = 0;
	it->j = 0;
	it->src = input;
	it->dest = input;
	it->flag = true;
	return (0);
}

bool	handle_quotes(char **input)
{
	t_iterators	it;

	if (set_iterators(&it, *input))
		return (false);
	while (it.src[it.i])
	{
		if (it.src[it.i] == '\'')
		{
			if (skip_char(&it, '\'', 1))
				break ;
		}
		else if (it.src[it.i] == '"')
		{
			if (skip_char(&it, '"', 0))
				break ;
		}
		else
			it.dest[it.j++] = it.src[it.i++];
	}
	while (it.dest[it.j])
		it.dest[it.j++] = '\0';
	*input = it.dest;
	return (it.flag);
}
