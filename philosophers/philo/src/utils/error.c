/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:24:16 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/30 18:58:25 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	free_program(t_program *program, int d_mutex)
{
	if (d_mutex)
		destroy_mutex(program);
	free(program->forks);
	free(program->fork_status);
	free(program->philos);
	free(program);
}
