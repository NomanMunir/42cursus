/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:53:04 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/31 11:24:30 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		sem_wait(philo->block_meal);
		if ((get_current_time() - philo->t_meal > philo->t_die)
			&& philo->eating == 0)
		{
			sem_post(philo->block_meal);
			printing(philo, "died", 0);
			sem_post(philo->block_stop);
			break ;
		}
		if (philo->num_eat != -1 && philo->num_eat_count >= philo->num_eat)
		{
			sem_post(philo->block_meal);
			sem_post(philo->block_stop);
			break ;
		}
		sem_post(philo->block_meal);
	}
	return (NULL);
}
