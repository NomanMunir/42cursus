/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:56:28 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:55:48 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead != NULL && *(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	printing(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->write_lock);
	if (is_dead(philo))
		return (pthread_mutex_unlock(philo->write_lock), 1);
	printf("%lu %d %s\n", get_current_time() - philo->start_time, philo->id,
		str);
	pthread_mutex_unlock(philo->write_lock);
	return (0);
}

int	eating(t_philo *philo)
{
	if (printing(philo, "has taken a fork"))
		return (1);
	if (printing(philo, "is eating"))
		return (1);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time() - philo->start_time;
	philo->eating = 1;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_lock(philo->meal_lock);
	if (philo->num_times_to_eat != -1
		&& philo->meals_eaten < philo->num_times_to_eat)
		philo->meals_eaten++;
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}
