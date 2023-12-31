/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:07:29 by abashir           #+#    #+#             */
/*   Updated: 2023/12/30 12:11:55 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define EAT "is eating"

typedef struct s_philo
{
	int			num_philos;
	size_t		t_die;
	size_t		t_eat;
	size_t		t_sleep;
	int			num_eat;
	int			num_eat_count;
	int			eating;
	int			*pid;
	int			index;
	sem_t		*block_write;
	sem_t		*block_fork;
	sem_t		*block_stop;
	sem_t		*block_meal;
	size_t		t_start;
	size_t		t_meal;
	pthread_t	t_monitor;
}				t_philo;

int				check_input(int argc, char **argv);
int				ft_isdigit(int c);
void			error_exit(int error);
int				ft_atoi(const char *str);
int				ft_usleep(size_t milliseconds);
size_t			get_current_time(void);
t_philo			*init_philo(char **argv);
void			routine(t_philo *philo);
void			create_process(t_philo *philo);
void			kill_process(t_philo *philo);
void			*monitor(void *p);
int				printing(t_philo *philo, char *str, int flag);
void			free_philo(t_philo *philo);
#endif
