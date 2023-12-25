/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:57:36 by nmunir            #+#    #+#             */
/*   Updated: 2023/11/26 11:33:46 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	return (pid);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	is_space(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (true);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (true);
	return (false);
}

int	ft_peek(char **ps, char *es, char *toks)
{
	char	*s;

	s = *ps;
	while (s < es && ft_strchr(" \t\r\n\v", *s))
		s++;
	*ps = s;
	return (*s && ft_strchr(toks, *s));
}

bool	check_access(char *path_to_cmd)
{
	if (access(path_to_cmd, F_OK) == 0)
		return (true);
	return (false);
}
