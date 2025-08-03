/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:33:08 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/18 19:14:45 by nmunir           ###   ########.fr       */
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

// #include "string.h"
// #include "stdio.h"
// int main(void)
// {
// 	char ft_s1[20] = "";
// 	char ft_s2[] = "World!";
// 	char s1[20] = "NULL";
// 	char s2[] = "WORLD!";
// 	printf("%zu \n", ft_strlcat(ft_s1, ft_s2, 0));
// 	printf("%lu", strlcat(s1, s2, 0));
// 	return (0);
// }