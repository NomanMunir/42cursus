/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:53:25 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/22 21:38:45 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *str)
{
	int		i;
	int		error;
	long	tmp;

	i = 0;
	error = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	tmp = ft_atol(str, &error);
	if (tmp > 2147483647 || tmp < -2147483648 || error == 1)
		return (0);
	return (1);
}

int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static char	**create_args(char **av)
{
	char	*tmp_arg;
	char	*args;
	char	**split;
	int		i;

	i = 1;
	if (ft_isspace(av[i]))
		return (error_handling(), NULL);
	args = ft_strjoin(av[i++], " ");
	while (av[i])
	{
		if (ft_isspace(av[i]))
			return (free(args), error_handling(), NULL);
		tmp_arg = ft_strjoin(args, av[i]);
		free(args);
		args = ft_strjoin(tmp_arg, " ");
		free(tmp_arg);
		i++;
	}
	split = ft_split(args, ' ');
	if (!split)
		return (error_handling(), NULL);
	free(args);
	return (split);
}

static int	check_valid(char *str)
{
	int	i;

	i = 0;
	if (!str || *str == '\0' || ft_isspace(str))
		return (0);
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i])
			&& str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**check_arg(char **av)
{
	int		i;
	char	**args;

	i = 0;
	args = av + 1;
	while (args[i])
		if (!check_valid(args[i++]))
			return (error_handling(), NULL);
	i = -1;
	args = create_args(av);
	if (!args)
		return (ft_free(args), error_handling(), NULL);
	while (args[++i])
		if (!is_num(args[i]))
			return (ft_free(args), error_handling(), NULL);
	return (args);
}
