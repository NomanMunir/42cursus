/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:12:26 by abashir           #+#    #+#             */
/*   Updated: 2023/12/30 18:46:06 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	(void)argc;
	if (check_input(argc, argv))
		return (1);
	philo = init_philo(argv);
	create_process(philo);
	kill_process(philo);
	return (0);
}
