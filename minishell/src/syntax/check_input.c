/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:05:56 by abashir           #+#    #+#             */
/*   Updated: 2023/12/11 11:40:16 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	handle_quotes_expand(char **argv, t_shell *shell)
{
	t_iterators	it;

	ft_memset(&it, 0, sizeof(t_iterators));
	it.i = 0;
	while (argv[it.i] != NULL)
	{
		it.tmp = expand_env(ft_strdup(argv[it.i]), shell);
		if (*it.tmp == '\0')
			it.i++;
		else
			argv[it.j++] = split_expand((argv[it.i++]), shell);
		free(it.tmp);
	}
	while (argv[it.j])
		argv[it.j++] = NULL;
	if (is_builtin(argv[0]))
		shell->is_builtins = true;
}

static int	set_args(t_iterators it, t_execcmd *args)
{
	char	*es;
	char	*q;
	char	*eq;

	q = NULL;
	eq = NULL;
	es = it.src + ft_strlen(it.src);
	while (it.src < es)
	{
		it.c = gettoken(&it.src, es, &q, &eq);
		if (it.c == 'a')
		{
			args->argv[it.i] = q;
			args->eargv[it.i++] = eq;
		}
		if (it.i >= MAXARGS)
			return(ft_putendl_fd("too many args", 2), 1);
	}
	args->argv[it.i] = NULL;
	args->eargv[it.i] = NULL;
	while (args->argv[it.j])
		*args->eargv[it.j++] = 0;
	return (0);
}

static int	cmd_builtins(char *input, t_shell *shell)
{
	t_execcmd	args;
	t_iterators	it;

	ft_memset(&it, 0, sizeof(t_iterators));
	ft_memset(&args, 0, sizeof(t_execcmd));
	it.src = ft_strdup(input);
	it.tmp = it.src;
	if (set_args(it, &args))
	{
		shell->g_exit_code = 1;
		return (free(it.tmp), 1);
	}
	handle_quotes_expand(args.argv, shell);
	free(it.tmp);
	if (args.argv[0] == NULL)
	{
		shell->g_exit_code = 0;
		return (free_argv(args.argv), 1);
	}
	return (free_argv(args.argv), 0);
}

char	*check_input(char *input, t_shell *shell)
{
	if (!input)
		return (NULL);
	shell->input = input;
	add_history(input);
	while (*input == ' ')
		input++;
	if (input[0] == '\0')
		return (input);
	if ((ft_strchr("'\"&;|<>", *input) && input[1] == '\0')
		|| ft_strchr("(&|;)", input[0]))
		return (syntax_error(input[0]), "");
	if (check_syntax(input))
		return ("");
	if (input == NULL)
		return (NULL);
	if (cmd_builtins(input, shell))
		return ("");
	return (shell->input);
}
