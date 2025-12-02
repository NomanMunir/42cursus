/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:29:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/18 18:51:07 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int			length;
	long long	num;

	num = n;
	length = 0;
	if (num < 0)
	{
		length++;
		num *= -1;
	}
	while (num > 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

static char	*get_result(int index, char *str, long long n)
{
	while (n > 0)
	{
		str[index - 1] = (char)((n % 10) + '0');
		index--;
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			digit_count;
	char		*result;
	long long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	digit_count = count_digits(n);
	if (num < 0)
		num *= -1;
	result = (char *)malloc((digit_count + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[digit_count] = '\0';
	if (n < 0)
		result[0] = '-';
	return (get_result(digit_count, result, num));
}
