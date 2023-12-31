/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:54:13 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:55:45 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	sleep_and_think(t_philo *philo)
{
	if (printing(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->time_to_sleep, philo);
	if (printing(philo, "is thinking"))
		return (1);
	usleep(1000);
	return (0);
}

int	is_greedy(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	if (*(philo->right_status) == philo->id
		&& *(philo->left_status) == philo->id)
	{
		*(philo->right_status) += 1000;
		*(philo->left_status) += 1000;
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}

static int	ft_even(t_philo *philo)
{
	if (printing(philo, "is thinking"))
		return (1);
	ft_usleep(philo->time_to_eat, philo);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		if (ft_even(philo))
			return (NULL);
	}
	while (is_dead(philo) != 1 && philo->num_of_philos != 1)
	{
		if (take_forks(philo))
			return (NULL);
		if (is_greedy(philo))
		{
			if (is_dead(philo))
				return (NULL);
			continue ;
		}
		if (eating(philo))
			return (NULL);
		drop_forks(philo, 1, 1);
		if (sleep_and_think(philo))
			return (NULL);
	}
	return (NULL);
}
