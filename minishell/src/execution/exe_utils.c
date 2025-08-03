/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:50:52 by abashir           #+#    #+#             */
/*   Updated: 2023/12/06 11:28:30 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	iterator(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

static void	count_cases(char *str, t_iterators *it)
{
	if (it->flag)
	{
		it->c = str[it->i];
		iterator(&it->i, &it->count);
		while (str[it->i] && str[it->i] != it->c)
			iterator(&it->i, &it->count);
		if (str[it->i] == it->c)
			iterator(&it->i, &it->count);
	}
	else
	{
		if (my_strchr(SPEC_CHAR, str[it->i]) || str[it->i] == ' ')
		{
			if (str[it->i] == '$' && (str[it->i + 1] == '\'' || str[it->i \
				+ 1] == '\"'))
				it->count--;
			iterator(&it->i, &it->count);
		}
		while (str[it->i] && !my_strchr(SPEC_CHAR_SPC, str[it->i]))
			iterator(&it->i, &it->count);
	}
}

int	count_split(char *str)
{
	t_iterators	it;

	ft_memset(&it, 0, sizeof(t_iterators));
	while (str[it.i])
	{
		if (str[it.i] == '\"' || str[it.i] == '\'')
			it.flag = 1;
		else
			it.flag = 0;
		count_cases(str, &it);
		it.count++;
	}
	return (it.count);
}
