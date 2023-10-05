/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:11:36 by alaa              #+#    #+#             */
/*   Updated: 2023/10/05 10:48:13 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
typedef struct s_pipex
{
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		cmd_count;
	char	**path;
	char	**cmds;
	char	***args;
	char	*infile;
	char	*outfile;
	bool	file_error;
	bool	is_error_file;
}			t_pipex;

void		ft_open_files(t_pipex *pipex, char **argv);
void		ft_init_pipe(t_pipex *pipex, char **envp);
bool		is_space(char *str);
void		validate_args(int argc, char **argv, t_pipex *pipex);
void		ft_free_pipex(t_pipex *pipex, bool flag);
void		error_exit(char *str, int flag, t_pipex *pipex);
void		check_error(int condition, char *str, int flag, t_pipex *pipex);
void		print_3d_array(t_pipex *pipex);
void		print_2d_array(char **tab);
int			ft_strcmp(const char *s1, const char *s2);
void		init_here_doc(t_pipex *pipex, char **argv);
void		process_pipes(t_pipex *pipex);
char		*ft_strjoin_3(char const *s1, char const *s2, char const *s3);

#endif
