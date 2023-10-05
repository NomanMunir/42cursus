/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:32:12 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/09 11:32:13 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	p = (char *)malloc(len * sizeof(char));
	if (p != NULL)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
