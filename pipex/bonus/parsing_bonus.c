/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:36:44 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/05 10:41:30 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static bool	set_is_here_doc(t_pipex *pipex, char *arg)
{
	char	*trim;

	trim = ft_strtrim(arg, " ");
	check_error(!trim, "malloc", 1, pipex);
	if (ft_strncmp(trim, "here_doc", 8) == 0)
		pipex->is_here_doc = true;
	free(trim);
	return (pipex->is_here_doc);
}

static bool	set_is_error_file(t_pipex *pipex, char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (!pipex->is_here_doc && fd == -1)
		pipex->is_error_file = true;
	else
		close(fd);
	return (pipex->is_error_file);
}

static void	creat_args(t_pipex *pipex, char **argv, int j)
{
	int	i;

	i = 0;
	pipex->args = ft_calloc(sizeof(char **), (pipex->cmd_count + 1));
	check_error(!pipex->args, "malloc", 1, pipex);
	while (i < pipex->cmd_count)
	{
		if (!is_space(argv[j]))
		{
			pipex->args[i] = ft_split(argv[j], ' ');
			check_error(!pipex->args[i], "malloc", 1, pipex);
			i++;
		}
		j++;
	}
	pipex->args[i] = NULL;
}

void	validate_args(int argc, char **argv, t_pipex *pipex)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 2;
	if (set_is_here_doc(pipex, argv[1]))
		i++;
	if (set_is_error_file(pipex, argv[1]))
		i++;
	j = i;
	while (i < argc - 1)
		if (!is_space(argv[i++]))
			count++;
	pipex->cmd_count = count;
	if (count == 0)
		return (error_exit("Invalid directory", 1, pipex));
	creat_args(pipex, argv, j);
	pipex->outfile = argv[argc - 1];
}
