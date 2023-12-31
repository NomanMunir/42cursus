/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:57:49 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/31 11:18:22 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_sem(t_philo *philo)
{
	int	i;

	i = -1;
	sem_unlink("/write");
	sem_unlink("/forks");
	sem_unlink("/stop");
	sem_unlink("/meal");
	philo->block_write = sem_open("/write", O_CREAT, 0644, 1);
	if (philo->block_write == SEM_FAILED)
		return (free_philo(philo), error_exit(8));
	philo->block_fork = sem_open("/forks", O_CREAT, 0644, 0);
	if (philo->block_fork == SEM_FAILED)
		return (free_philo(philo), error_exit(8));
	while (++i < philo->num_philos)
		sem_post(philo->block_fork);
	philo->block_stop = sem_open("/stop", O_CREAT, 0644, 0);
	if (philo->block_stop == SEM_FAILED)
		return (free_philo(philo), error_exit(8));
	philo->block_meal = sem_open("/meal", O_CREAT, 0644, 1);
	if (philo->block_meal == SEM_FAILED)
		return (free_philo(philo), error_exit(8));
}

static t_philo	*allocate_mem(char **argv)
{
	t_philo	*philo;
	int		nop;

	nop = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (printf("Error: malloc failed\n"), exit(1), NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->pid = malloc(sizeof(int) * nop);
	if (!philo->pid)
		return (printf("Error: malloc failed\n"), free(philo), exit(1), NULL);
	memset(philo->pid, 0, sizeof(int) * nop);
	return (philo);
}

t_philo	*init_philo(char **argv)
{
	t_philo	*philo;

	philo = allocate_mem(argv);
	philo->num_philos = ft_atoi(argv[1]);
	philo->t_die = ft_atoi(argv[2]);
	philo->t_eat = ft_atoi(argv[3]);
	philo->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_eat = ft_atoi(argv[5]) + 1;
	else
		philo->num_eat = -1;
	philo->t_start = get_current_time();
	init_sem(philo);
	return (philo);
}

void	create_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philos)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] < 0)
			return (free_philo(philo), error_exit(9));
		if (philo->pid[i] == 0)
		{
			philo->index = i + 1;
			philo->t_meal = get_current_time();
			routine(philo);
		}
		i++;
	}
	sem_wait(philo->block_stop);
}
