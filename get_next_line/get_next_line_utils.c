/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:03:56 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/05 13:21:08 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	if (!buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (*buff != '\0')
		str[i++] = *buff++;
	str[i] = '\0';
	free(left_str);
	return (str);
}

char	*ft_get_first_line(char *rem_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!rem_str[i])
		return (NULL);
	while (rem_str[i] && rem_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rem_str[i] && rem_str[i] != '\n')
	{
		str[i] = rem_str[i];
		i++;
	}
	if (rem_str[i] == '\n')
	{
		str[i] = rem_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_new_rem_str(char *rem_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rem_str[i] && rem_str[i] != '\n')
		i++;
	if (!rem_str[i])
	{
		free(rem_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rem_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	if (!rem_str[i])
		return (free(str), free(rem_str), NULL);
	j = 0;
	while (rem_str[i])
		str[j++] = rem_str[i++];
	str[j] = '\0';
	free(rem_str);
	return (str);
}
