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
	bool	nagetive;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			nagetive = true;
	}
	while (ft_isdigit(*str))
	{
		if (nagetive && (result * 100) < result)
			return (0);
		else if (!nagetive && (result * 100) < result)
			return (-1);
		result = result * 10 + (*str++ - '0');
	}
	if (nagetive)
		result = -result;
	return (result);
}

// #include "stdio.h"
// int main(int a, char **av)
// {
// 	printf("%d \n", ft_atoi(av[1]));
// 	printf("%d", atoi(av[1]));
// 	return (0);
// }