/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:46:00 by abashir           #+#    #+#             */
/*   Updated: 2023/12/10 08:05:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	count_digits(int num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	count_env(char *input, t_shell *shell, int *count)
{
	char	c;
	int		i;

	i = 0;
	while (input[i] && input[i] != ' ' && input[i] != '\'' && input[i] != '"'
		&& input[i] != '$' && input[i] != '/' && input[i] != '=')
		i++;
	c = input[i];
	input[i] = '\0';
	if (find_env(shell->env_list, input))
	{
		if (find_env(shell->env_list, input)->value)
			*count = *count + ft_strlen(find_env(shell->env_list,
						input)->value);
	}
	input[i] = c;
	return (i);
}

int	count_expand(char *input, t_shell *shell)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (input[++i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
		{
			count += count_digits(shell->g_exit_code);
			i++;
		}
		else if (input[i] == '$' && ft_isalnum(input[i + 1]))
		{
			input += ++i;
			i = count_env(input, shell, &count);
			input += i;
			i = -1;
		}
		else
			count++;
	}
	return (count);
}
