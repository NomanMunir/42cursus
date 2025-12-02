/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:46:43 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/04 11:09:20 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	bool	negative;

	result = 0;
	negative = false;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = true;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (negative && ((result * 10) + *str - '0') < result)
			return (0);
		else if (!negative && ((result * 10) + *str - '0') < result)
			return (-1);
		result = result * 10 + (*str++ - '0');
	}
	if (negative)
		result = -result;
	return (result);
}
