/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:06:21 by abashir           #+#    #+#             */
/*   Updated: 2023/12/06 15:42:25 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	my_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static void	split_join(t_iterators *it, t_shell *shell)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_split(it->dest, '\n');
	free(it->dest);
	while (split[++i])
	{
		if (handle_quotes(&split[i]) && my_strchr(split[i], '$'))
		{
			split[i] = expand_env(split[i], shell);
			if (split[i] == NULL)
				return (ft_malloc_error(), panic(shell, 1, 1));
		}
	}
	i = 0;
	while (split[i])
	{
		it->src = ft_strjoin_gnl(it->src, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

static void	fill_split(char *str, t_iterators *it, int flag)
{
	if (flag)
	{
		it->c = str[it->i];
		it->dest[it->j++] = str[it->i++];
		while (str[it->i] && str[it->i] != it->c)
			it->dest[it->j++] = str[it->i++];
		if (str[it->i] == it->c)
			it->dest[it->j++] = str[it->i++];
		it->dest[it->j++] = '\n';
	}
	else
	{
		if (str[it->i] == '$' && (str[it->i + 1] == '\'' || str[it->i \
			+ 1] == '"'))
			it->i++;
		if (my_strchr(SPEC_CHAR, str[it->i]) || str[it->i] == ' ')
			it->dest[it->j++] = str[it->i++];
		while (str[it->i] && !my_strchr(SPEC_CHAR_SPC, str[it->i]))
			it->dest[it->j++] = str[it->i++];
		it->dest[it->j++] = '\n';
	}
}

char	*split_expand(char *str, t_shell *shell)
{
	t_iterators	it;

	ft_memset(&it, 0, sizeof(t_iterators));
	if (!str)
		return (NULL);
	it.dest = (char *)ft_calloc(sizeof(char), (count_split(str) + 1));
	if (!it.dest)
		ft_malloc_error();
	while (str[it.i])
	{
		if (str[it.i] == '\"' || str[it.i] == '\'')
			fill_split(str, &it, 1);
		else
			fill_split(str, &it, 0);
	}
	it.dest[it.j] = '\0';
	split_join(&it, shell);
	return (it.src);
}
