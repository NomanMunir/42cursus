/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:27:18 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 10:01:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_put_error(char *errmsg, char *errcmd, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(errcmd, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(errmsg, 2);
}

void	ft_malloc_error(void)
{
	if (errno == ENOMEM)
		perror("Memory allocation failed");
	else
		perror("Malloc failed for an unknown reason");
}

void	panic(t_shell *shell, int e_code, bool flag)
{
	ft_free_tree(shell->cmd, shell);
	ft_free(shell->env);
	ft_clean_env(shell->env_list);
	if (shell->input)
		free(shell->input);
	shell = NULL;
	close(0);
	close(1);
	if (flag)
		exit(e_code);
}

void	parse_panic(t_shell *shell, int e_code, bool flag, t_cmd *cmd)
{
	ft_free_tree(cmd, shell);
	ft_free(shell->env);
	ft_clean_env(shell->env_list);
	if (shell->input)
		free(shell->input);
	shell = NULL;
	close(0);
	close(1);
	if (flag)
		exit(e_code);
}
