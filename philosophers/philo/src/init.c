/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:54:21 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:56:22 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_philos(t_philo *philo, t_program *program)
{
	int		i;
	t_args	args;

	i = 0;
	args = program->args;
	while (i < args.num_of_philos)
	{
		philo[i].right_status = &program->fork_status[(i + 1)
			% args.num_of_philos];
		philo[i].left_status = &program->fork_status[i];
		philo[i].r_fork = &program->forks[(i + 1) % args.num_of_philos];
		philo[i].l_fork = &program->forks[i];
		philo[i].id = i + 1;
		philo[i].num_of_philos = args.num_of_philos;
		philo[i].time_to_die = args.time_to_die;
		philo[i].time_to_eat = args.time_to_eat;
		philo[i].time_to_sleep = args.time_to_sleep;
		philo[i].start_time = get_current_time();
		philo[i].num_times_to_eat = args.num_times_to_eat;
		i++;
	}
}

int	init_mutex(t_program *program)
{
	int		i;
	t_philo	*philo;

	i = 0;
	program->time_to_die = program->args.time_to_die;
	philo = program->philos;
	program->dead_flag = 0;
	if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&program->meal_lock, NULL) != 0)
		return (pthread_mutex_destroy(&program->dead_lock), 1);
	if (pthread_mutex_init(&program->write_lock, NULL) != 0)
		return (pthread_mutex_destroy(&program->dead_lock),
			pthread_mutex_destroy(&program->meal_lock), 1);
	while (i < program->args.num_of_philos)
	{
		philo[i].write_lock = &(program->write_lock);
		philo[i].meal_lock = &(program->meal_lock);
		philo[i].dead_lock = &(program->dead_lock);
		philo[i].dead = &(program->dead_flag);
		i++;
	}
	return (0);
}

int	create_threads(t_program *program)
{
	int			i;
	pthread_t	t_mon;
	t_philo		*philo;

	i = 0;
	philo = program->philos;
	pthread_create(&t_mon, NULL, &monitor, program);
	while (i < program->args.num_of_philos)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	if (join_threads(program, t_mon))
		return (1);
	return (0);
}
