/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:09:41 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/08 14:49:53 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*is_new_line(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *rem, char *buf)
{
	int		i;
	char	*joined_str;

	i = -1;
	if (!rem)
	{
		rem = (char *) malloc(sizeof(char) * 1);
		if (rem == NULL)
			return (NULL);
		rem[0] = '\0';
	}
	joined_str = malloc(sizeof(char) * ((ft_strlen(rem) + ft_strlen(buf)) + 1));
	if (joined_str == NULL)
		return (NULL);
	while (rem[++i] != '\0')
		joined_str[i] = rem[i];
	while (*buf != '\0')
		joined_str[i++] = *buf++;
	joined_str[i] = '\0';
	free(rem);
	return (joined_str);
}

char	*get_first_line(char *rem_str)
{
	int		i;
	char	*res;

	i = 0;
	if (!rem_str[i])
		return (NULL);
	while (rem_str[i] && rem_str[i] != '\n')
		i++;
	if (rem_str[i] == '\n')
		i++;
	res = (char *) malloc(sizeof(char) * (1 + i));
	if (!res)
		return (NULL);
	i = -1;
	while (rem_str[++i] && rem_str[i] != '\n')
		res[i] = rem_str[i];
	if (rem_str[i] == '\n')
	{
		res[i] = rem_str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_new_rem_str(char *rem_str)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	while (rem_str[i] && rem_str[i] != '\n')
		i++;
	if (!rem_str[i])
	{
		free(rem_str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(rem_str) + 1 - i));
	if (!res)
		return (NULL);
	if (!rem_str[i])
		return (free(rem_str), free(res), NULL);
	i++;
	while (rem_str[i])
		res[j++] = rem_str[i++];
	res[j] = '\0';
	free(rem_str);
	return (res);
}
