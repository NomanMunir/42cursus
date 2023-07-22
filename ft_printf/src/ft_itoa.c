/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:29:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/22 14:36:15 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_int_length(int n)
{
	int			length;
	long long	temp;

	temp = n;
	length = 0;
	if (temp < 0)
	{
		length++;
		temp *= -1;
	}
	while (temp > 0)
	{
		length++;
		temp /= 10;
	}
	return (length);
}

static char	*get_result(int size, char *str, long n)
{
	while (n > 0)
	{
		str[size - 1] = (char)((n % 10) + '0');
		size--;
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	int			int_length;
	int			sign;
	char		*result;

	if (n == 0)
	{
		result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	int_length = count_int_length(n);
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	result = (char *)malloc((int_length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[int_length] = '\0';
	if (sign == -1)
		result[0] = '-';
	return (get_result(int_length, result, n));
}
