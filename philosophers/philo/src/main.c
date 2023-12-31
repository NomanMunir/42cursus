/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:58:38 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/31 16:45:35 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_program	*allocate_mem(t_args args)
{
	t_program	*program;
	t_philo		*philos;

	program = malloc(sizeof(t_program));
	if (!program)
		return (printf("Error: malloc failed\n"), NULL);
	memset(program, 0, sizeof(t_program));
	philos = malloc(sizeof(t_philo) * args.num_of_philos);
	if (!philos)
		return (printf("Error: malloc failed\n"), free(program), NULL);
	memset(philos, 0, sizeof(t_philo) * args.num_of_philos);
	program->forks = malloc(sizeof(pthread_mutex_t) * args.num_of_philos);
	if (!program->forks)
		return (printf("Error: malloc failed\n"), free(program), free(philos),
			NULL);
	memset(program->forks, 0, sizeof(pthread_mutex_t) * args.num_of_philos);
	program->fork_status = malloc(sizeof(int) * args.num_of_philos);
	if (!program->fork_status)
		return (printf("Error: malloc failed\n"), free(program), free(philos),
			free(program->forks), NULL);
	memset(program->fork_status, 0, sizeof(int) * args.num_of_philos);
	program->philos = philos;
	return (program);
}

static int	exe(t_args args)
{
	int			i;
	t_program	*program;

	i = 0;
	program = allocate_mem(args);
	if (!program)
		return (1);
	program->args = args;
	while (i < args.num_of_philos)
		pthread_mutex_init(&program->forks[i++], NULL);
	init_philos(program->philos, program);
	if (init_mutex(program))
		return (free_program(program, 0), 1);
	if (create_threads(program))
		return (free_program(program, 1), 1);
	free_program(program, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (check_input(argc, argv))
		return (1);
	setargs(&args, argv);
	if (exe(args))
		return (1);
	return (0);
}
