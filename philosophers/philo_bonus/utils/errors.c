/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:38:41 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/31 11:24:48 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	free_philo(t_philo *philo)
{
	if (philo->pid)
		free(philo->pid);
	if (philo)
		free(philo);
	sem_unlink("/write");
	sem_unlink("/forks");
	sem_unlink("/stop");
	sem_unlink("/meal");
}

void	error_exit(int error)
{
	if (error == 1)
		printf("Usage: no_philos time_die time_eat time_sleep \
		[no_of_times_eat]\n");
	if (error == 2)
		printf("Error: Number of philos must be between 1 and 200.\n");
	if (error == 3)
		printf("Error: Time is Invalid.\n");
	if (error == 5)
		printf("Error: Empty argument.\n");
	if (error == 6)
		printf("Error: Input must be a number.\n");
	if (error == 7)
		printf("Error: Thread creation failed.\n");
	if (error == 8)
		printf("Error: Semaphore creation failed.\n");
	if (error == 9)
		printf("Error: Process creation failed.\n");
	exit(1);
}
