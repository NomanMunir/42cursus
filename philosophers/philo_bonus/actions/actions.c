/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:47:20 by abashir           #+#    #+#             */
/*   Updated: 2023/12/31 11:17:03 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	printing(t_philo *philo, char *str, int flag)
{
	sem_wait(philo->block_write);
	printf("%lu %d %s\n", get_current_time() - philo->t_start, philo->index,
		str);
	if (flag == 1)
		sem_post(philo->block_write);
	return (0);
}

static void	eating(t_philo *philo)
{
	printing(philo, FORK, 1);
	printing(philo, EAT, 1);
	sem_wait(philo->block_meal);
	philo->t_meal = get_current_time();
	philo->eating = 1;
	sem_post(philo->block_meal);
	ft_usleep(philo->t_eat);
	sem_wait(philo->block_meal);
	philo->eating = 0;
	philo->num_eat_count++;
	sem_post(philo->block_meal);
	sem_post(philo->block_fork);
	sem_post(philo->block_fork);
}

static void	sleep_think(t_philo *philo)
{
	printing(philo, SLEEP, 1);
	ft_usleep(philo->t_sleep);
	printing(philo, THINK, 1);
	usleep(1000);
}

void	routine(t_philo *philo)
{
	if (pthread_create(&philo->t_monitor, NULL, &monitor, philo) != 0)
	{
		printing(philo, "Error: Thread creation failed.", 1);
		sem_post(philo->block_stop);
	}
	pthread_detach(philo->t_monitor);
	if (philo->index % 2 == 0)
	{
		printing(philo, THINK, 1);
		ft_usleep(philo->t_eat);
	}
	while (1)
	{
		sem_wait(philo->block_fork);
		sem_wait(philo->block_fork);
		eating(philo);
		sleep_think(philo);
	}
}
