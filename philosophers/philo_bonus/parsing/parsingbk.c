/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:24:36 by abashir           #+#    #+#             */
/*   Updated: 2023/12/30 11:48:42 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	check_args_empty(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			error_exit(5);
		if (argv[i][j] == ' ')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '\0')
				error_exit(5);
		}
		i++;
	}
}

void	check_args_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-'
				&& argv[i][j] != '+' && argv[i][j] != ' ')
				error_exit(6);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j
				- 1] != ' ' && j != 0)
				error_exit(6);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (argv[i][j + 1] == '\0' || ft_isdigit(argv[i][j + 1]) == 0)
					error_exit(6);
			j++;
		}
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	check_args_empty(argc, argv);
	check_args_char(argc, argv);
}

int	check_input(int argc, char **argv)
{
	int			j;
	long long	num;

	j = 2;
	if (argc != 5 && argc != 6)
		error_exit(1);
	check_args(argc, argv);
	num = ft_atoi(argv[1]);
	if (num < 1 || num > 200 || num > 2147483647)
		error_exit(2);
	while (j < argc - 1)
	{
		num = ft_atoi(argv[j]);
		if (num < 0 || num > 2147483647)
			error_exit(3);
		j++;
	}
	if (argc == 6 && (ft_atoi(argv[5]) < 0 || ft_atoi(argv[5]) > 2147483647))
		error_exit(3);
	return (0);
}
