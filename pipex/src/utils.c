/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:33:57 by nmunir            #+#    #+#             */
/*   Updated: 2023/10/04 10:55:51 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if ((s1[i] == '\0' && (s2[i] == '\n')))
		return (0);
	return (s1[i] - s2[i]);
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

char	*ft_strjoin_3(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	new = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) \
			+ ft_strlen(s3) + 1));
	if (new == NULL)
		return ((char *) NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	j = -1;
	while (s3[++j] != '\0')
		new[i++] = s3[j];
	new[i] = '\0';
	return (new);
}
