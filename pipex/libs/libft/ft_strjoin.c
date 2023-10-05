/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:32:23 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/14 15:02:01 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	lens1;
	size_t	lens2;
	size_t	totallen;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	totallen = lens1 + lens2 + 1;
	joined = (char *)malloc(sizeof(char) * totallen);
	if (joined != NULL)
	{
		while (*s1)
			joined[i++] = *s1++;
		while (*s2)
			joined[i++] = *s2++;
		joined[i] = '\0';
	}
	return (joined);
}
