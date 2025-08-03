/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:59:46 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/24 21:56:43 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **rtn, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		free(rtn[j]);
	free(rtn);
}

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

char	**ft_words(char const *s, char c, char **words, size_t wrd_cnt)
{
	size_t	len;
	size_t	index;

	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] != c && s[len])
			len++;
		if (index < wrd_cnt)
		{
			words[index++] = ft_substr(s, 0, len);
			if (words[index - 1] == NULL)
				return (ft_free(words, index - 1), NULL);
		}
		s += len;
	}
	words[index] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	wrd_cnt;

	if (s == NULL)
		return (NULL);
	wrd_cnt = count_wrd(s, c);
	words = (char **)malloc(sizeof(char *) * (wrd_cnt + 1));
	if (words == NULL)
		return (NULL);
	words = ft_words(s, c, words, wrd_cnt);
	return (words);
}
