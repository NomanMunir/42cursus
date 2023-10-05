/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:39:09 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/17 16:39:01 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

static size_t	sublength(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (s1[start] && (is_char_in_set(s1[start], set)))
		start++;
	while (s1[end])
		end++;
	end--;
	while (end > start && is_char_in_set(s1[end], set))
		end--;
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*result;
	size_t	total_len;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	while (s1[start] && (is_char_in_set(s1[start], set)))
		start++;
	total_len = sublength(s1, set);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	while (i < total_len)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
