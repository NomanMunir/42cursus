/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:46:43 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/14 15:52:00 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	substrlen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	substrlen = 0;
	if (start >= slen)
		return (ft_strdup(""));
	while (substrlen < len && s[substrlen + start])
		substrlen++;
	substr = (char *)malloc((substrlen + 1) * sizeof(char));
	if (substr != NULL)
	{
		substr[substrlen] = '\0';
		ft_strlcpy(substr, s + start, substrlen + 1);
	}
	return (substr);
}
