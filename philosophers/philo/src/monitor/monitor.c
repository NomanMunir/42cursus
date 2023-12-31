/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:11:43 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:55:55 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	monitor_print(t_program *program, char *msg, int i)
{
	pthread_mutex_lock(&program->dead_lock);
	program->dead_flag = 1;
	pthread_mutex_unlock(&program->dead_lock);
	if (i != -1)
	{
		pthread_mutex_lock(&program->write_lock);
		printf("%lu %d %s\n", get_current_time()
			- program->philos[i].start_time, program->philos[i].id, msg);
		pthread_mutex_unlock(&program->write_lock);
	}
}

static int	is_time_to_die(t_program *program, int i)
{
	pthread_mutex_lock(&program->meal_lock);
	if ((get_current_time() - program->philos[i].start_time
			- program->philos[i].last_meal) > program->philos[i].time_to_die
		+ 5)
	{
		pthread_mutex_unlock(&program->meal_lock);
		monitor_print(program, "died", i);
		return (1);
	}
	return (pthread_mutex_unlock(&program->meal_lock), 0);
}

int	philos_eaten(t_program *program, int i)
{
	int	j;

	j = 0;
	pthread_mutex_lock(&program->meal_lock);
	if (program->philos[i].num_times_to_eat != -1
		&& program->philos[i].meals_eaten == 
		program->philos[i].num_times_to_eat)
	{
		while (j < program->philos[0].num_of_philos)
		{
			if (program->philos[j].meals_eaten != 
				program->philos[j].num_times_to_eat)
				break ;
			j++;
		}
	}
	pthread_mutex_unlock(&program->meal_lock);
	if (j == program->philos[0].num_of_philos)
		return (1);
	return (0);
}

void	*monitor(void *p)
{
	int			i;
	t_program	*program;
	int			nop;

	program = (t_program *)p;
	nop = program->philos[0].num_of_philos;
	while (1)
	{
		i = 0;
		while (i < nop)
		{
			if (is_time_to_die(program, i))
				return (NULL);
			if (philos_eaten(program, i))
			{
				monitor_print(program, "All philos ate enough", -1);
				return (NULL);
			}
			i++;
		}
	}
}
