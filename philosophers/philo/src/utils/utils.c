/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:52:14 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:56:11 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		if (is_dead(philo))
			return (1);
		usleep(500);
	}
	return (0);
}

int	destroy_mutex(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->args.num_of_philos)
	{
		if (pthread_mutex_destroy(&program->forks[i++]) != 0)
			return (1);
	}
	if (pthread_mutex_destroy(&program->write_lock) != 0)
		return (1);
	if (pthread_mutex_destroy(&program->meal_lock) != 0)
		return (1);
	if (pthread_mutex_destroy(&program->dead_lock) != 0)
		return (1);
	return (0);
}

int	join_threads(t_program *program, pthread_t mon)
{
	int	i;

	i = 0;
	if (pthread_join(mon, NULL) != 0)
		return (printf("Error: pthread_join failed\n"), 1);
	while (i < program->args.num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (printf("Error: pthread_join failed\n"), 1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (res < 0)
			return (-1);
		res = res * 10 + (str[i++] - 48);
	}
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i] == '\0')
		return (res * sign);
	return (-1);
}
