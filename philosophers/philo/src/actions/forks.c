/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:36:55 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:55:32 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	is_fork_taken(t_philo *philo, int flag)
{
	if (flag)
	{
		pthread_mutex_lock(philo->r_fork);
		if (*(philo->right_status) != philo->id
			&& *(philo->right_status) < 1000)
			return (pthread_mutex_unlock(philo->r_fork), 0);
		else
			return (pthread_mutex_unlock(philo->r_fork), 1);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		if (*(philo->left_status) != philo->id && *(philo->left_status) < 1000)
			return (pthread_mutex_unlock(philo->l_fork), 0);
		else
			return (pthread_mutex_unlock(philo->l_fork), 1);
	}
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (is_fork_taken(philo, 1))
	{
		while (1)
		{
			usleep(100);
			if (is_dead(philo))
				return (1);
			if (!is_fork_taken(philo, 1))
				break ;
		}
	}
	if (is_fork_taken(philo, 0))
	{
		while (1)
		{
			usleep(100);
			if (is_dead(philo))
				return (1);
			if (!is_fork_taken(philo, 0))
				break ;
		}
	}
	set_forks(philo, 1, 1);
	return (0);
}

void	drop_forks(t_philo *philo, int right, int left)
{
	if (right)
	{
		pthread_mutex_lock(philo->r_fork);
		*(philo->right_status) -= 1000;
		pthread_mutex_unlock(philo->r_fork);
	}
	if (left)
	{
		pthread_mutex_lock(philo->l_fork);
		*(philo->left_status) -= 1000;
		pthread_mutex_unlock(philo->l_fork);
	}
}

void	set_forks(t_philo *philo, int right, int left)
{
	if (right)
	{
		pthread_mutex_lock(philo->r_fork);
		*(philo->right_status) = philo->id;
		pthread_mutex_unlock(philo->r_fork);
	}
	if (left)
	{
		pthread_mutex_lock(philo->l_fork);
		*(philo->left_status) = philo->id;
		pthread_mutex_unlock(philo->l_fork);
	}
}
