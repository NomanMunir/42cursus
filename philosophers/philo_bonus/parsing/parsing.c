/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:53:53 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:39:15 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (printf("Error: Usage: NOP TTD ms TTE ms TTS ms OPT\n"), 1);
	if (ft_atoi(argv[1]) < 1)
		return (printf("Error: Invalid no of philos\n"), 1);
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (printf("Error: Invalid Time.\n"), 1);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (printf("Error: Philo can not be less then or 0.\n"), 1);
	while (argv[++i])
	{
		if (!is_number(argv[i]))
			return (printf("Error: Invalid argument.\n"), 1);
	}
	return (0);
}
