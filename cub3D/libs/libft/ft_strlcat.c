/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:33:08 by nmunir            #+#    #+#             */
/*   Updated: 2024/01/29 17:33:23 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	totallen;
	size_t	i;

	srclen = 0;
	dstlen = 0;
	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0 && dst == NULL)
		return (0);
	while (dst[dstlen] && (dstlen < dstsize))
		dstlen++;
	totallen = (srclen + dstlen);
	if (dstsize <= dstlen)
		return (totallen);
	while (src[i] && (dstlen + 1 < dstsize))
		dst[dstlen++] = src[i++];
	if (dstlen < dstsize)
		dst[dstlen] = '\0';
	return (totallen);
}
