/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:00:05 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/04 09:26:59 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	s = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dest == s)
		return (dst);
	if (dest < s)
	{
		while (n--)
			*dest++ = *s++;
	}
	else
	{
		while (n--)
			dest[n] = s[n];
	}
	return (dst);
}
