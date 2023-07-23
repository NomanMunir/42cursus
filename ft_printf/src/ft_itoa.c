/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:29:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/23 18:24:49 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_length(int n)
{
	int			length;
	long		temp;

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

static char	*get_result(int nbr)
{
	int			sign;
	char		*result;
	int			length;
	long		n;

	sign = 1;
	n = nbr;
	length = count_length(n);
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	result = (char *)malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	if (sign == -1)
		result[0] = '-';
	while (n > 0)
	{
		result[length-- - 1] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char		*result;

	if (n == 0)
	{
		result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result = get_result(n);
	return (result);
}
