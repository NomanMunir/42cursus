/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:01:06 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 10:19:37 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_plus(char *input, t_shell *shell, int i)
{
	t_env	*tmp;
	char	*value;

	value = ft_substr(input, 0, i);
	tmp = find_env(shell->env_list, value);
	free(value);
	value = NULL;
	if (tmp)
	{
		if (input[i + 2] == '\0')
		{
			tmp->value = ft_strdup("");
			return ;
		}
		value = ft_substr(input, i + 2, ft_strlen(input));
		if (!tmp->value)
		{
			tmp->value = value;
			return ;
		}
		tmp->value = ft_strjoin_gnl(tmp->value, value);
		free(value);
	}
	else
		ft_set_export(input, shell, i, 1);
}

void	ft_export(t_shell *shell, char *input)
{
	int	i;

	i = 0;
	if (!input)
		return ;
	while (input[i] != '=' && input[i] != '\0')
		i++;
	ft_set_export(input, shell, i, 0);
	reset_env(shell);
}

static void	ft_validate_export(char *input, t_shell *shell)
{
	int	i;

	i = 0;
	if (ft_isdigit(input[i]) || input[i] == '=')
	{
		ft_put_error("not a valid identifier", "export: ", input);
		shell->g_exit_code = 1;
		return ;
	}
	while ((ft_isalnum(input[i]) || input[i] == '_') && input[i] != '\0')
		i++;
	if (input[i] && input[i + 1] == '=' && input[i] == '+')
		handle_plus(input, shell, i);
	else if (input[i] == '=' || input[i] == '\0')
		ft_export(shell, input);
	else
	{
		ft_put_error("not a valid identifier", "export: ", input);
		shell->g_exit_code = 1;
	}
}

int	handle_export(char **cmd, t_shell *shell)
{
	int	i;

	i = 0;
	shell->g_exit_code = 0;
	if (cmd[++i] == NULL)
	{
		free_argv(cmd);
		if (shell->is_one_command)
			return (ft_print_export(shell->env_list), ft_free_tree(shell->cmd,
					shell), 0);
		return (ft_print_export(shell->env_list), panic(shell, 0, 0), 0);
	}
	while (cmd[i])
	{
		ft_validate_export(cmd[i], shell);
		i++;
	}
	free_argv(cmd);
	if (shell->is_one_command)
		return (ft_free_tree(shell->cmd, shell), shell->g_exit_code);
	return (panic(shell, shell->g_exit_code, 1), shell->g_exit_code);
}
