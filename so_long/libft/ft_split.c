/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:59:46 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/04 15:20:09 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_wrd(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**words;
	size_t	index;
	size_t	wrd_cnt;

	if (s == NULL)
		return (NULL);
	index = 0;
	wrd_cnt = count_wrd(s, c);
	words = (char **)malloc(sizeof(char *) * (wrd_cnt + 1));
	if (words == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] != c && s[len])
			len++;
		if (index < wrd_cnt)
			words[index++] = ft_substr(s, 0, len);
		s += len;
	}
	words[index] = NULL;
	return (words);
}
