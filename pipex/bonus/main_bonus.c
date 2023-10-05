/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:33:40 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/03 19:55:04 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;

	check_error(ac < 4, "Error: Wrong number of arguments\n", 0, NULL);
	pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	check_error(!pipex, "malloc", 0, NULL);
	validate_args(ac, av, pipex);
	init_here_doc(pipex, av);
	ft_open_files(pipex, av);
	ft_init_pipe(pipex, envp);
	process_pipes(pipex);
	ft_free_pipex(pipex, true);
}
