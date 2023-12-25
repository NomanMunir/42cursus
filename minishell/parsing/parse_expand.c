/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:52:51 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 08:03:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_expander(char *input, t_shell *shell, t_iterators *it)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (input[i] && input[i] != ' ' && input[i] != '\'' && input[i] != '"'
		&& input[i] != '$' && input[i] != '/' && input[i] != '=')
		i++;
	it->c = input[i];
	input[i] = '\0';
	if (find_env(shell->env_list, input))
		tmp = find_env(shell->env_list, input)->value;
	if (tmp)
		while (*tmp)
			it->dest[it->j++] = *tmp++;
	input[i] = it->c;
	return (i);
}

static void	expand_exit_status(t_iterators *it, t_shell *shell)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_itoa(shell->g_exit_code);
	while (tmp[i])
		it->dest[it->j++] = tmp[i++];
	free(tmp);
	it->i++;
}

char	*expand_env(char *input, t_shell *shell)
{
	t_iterators	it;

	if (!input)
		return (NULL);
	it = (t_iterators){-1, 0, 0, 0, false, NULL, input, NULL, 0};
	it.dest = ft_calloc(sizeof(char) * (count_expand(input, shell) + 1), 1);
	while (input[++it.i])
	{
		if (input[it.i] == '$' && input[it.i + 1] == '?')
			expand_exit_status(&it, shell);
		else if (input[it.i] == '$' && (ft_isalnum(input[it.i + 1])
				|| input[it.i + 1] == '_'))
		{
			input += ++it.i;
			it.i = ft_expander(input, shell, &it);
			input += it.i;
			it.i = -1;
		}
		else
			it.dest[it.j++] = input[it.i];
	}
	it.dest[it.j] = '\0';
	free(it.src);
	return (it.dest);
}
