/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:52:14 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 16:34:39 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (res < 0)
			return (-1);
		res = res * 10 + (str[i++] - 48);
	}
	while (str[i] == ' ' && str[i])
		i++;
	if (str[i] == '\0')
		return (res * sign);
	return (-1);
}

void	kill_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philos)
		kill(philo->pid[i++], SIGKILL);
	sem_close(philo->block_write);
	sem_close(philo->block_fork);
	sem_close(philo->block_stop);
	sem_close(philo->block_meal);
	sem_unlink("/write");
	sem_unlink("/forks");
	sem_unlink("/stop");
	sem_unlink("/meal");
	free_philo(philo);
}
