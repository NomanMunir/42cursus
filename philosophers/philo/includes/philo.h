/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:58:03 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:58:05 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define EAT "is eating"

typedef struct s_args
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philos;
	int				num_times_to_eat;
}					t_args;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	int				*left_status;
	int				*right_status;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	size_t			time_to_die;
	int				*fork_status;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_args			args;
	t_philo			*philos;
}					t_program;

int					check_input(int argc, char **argv);
int					setargs(t_args *args, char **argv);
int					ft_usleep(size_t milliseconds, t_philo *philo);
size_t				get_current_time(void);
void				init_philos(t_philo *philo, t_program *program);
int					init_mutex(t_program *program);
void				drop_forks(t_philo *philo, int right, int left);
void				set_forks(t_philo *philo, int right, int left);
int					take_forks(t_philo *philo);
int					eating(t_philo *philo);
int					printing(t_philo *philo, char *str);
void				*routine(void *arg);
int					destroy_mutex(t_program *program);
int					is_dead(t_philo *philo);
void				*monitor(void *p);
int					create_threads(t_program *program);
int					join_threads(t_program *program, pthread_t mon);
int					ft_atoi(const char *str);
void				ft_error(char *str);
void				free_program(t_program *program, int d_mutex);
#endif
