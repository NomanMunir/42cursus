/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:13:38 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/20 20:09:43 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(long num)
{
	int	count;

	count = 0;
	

	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s)
	{
		while (*s)
		{
			count += write(1, s++, 1);
		}
	}
	return (count);
}

int	ft_putchar(int c)
{
	char	n;

	n = (char)c;
	return (write(1, &n, 1));
}

int	ft_putnbr(long nbr)
{
	int		count;
	long	temp;

	temp = nbr;
	if (temp == 0)
		return (1);
	if (temp < 0)
	{
		count++;
		temp = -temp;
	}
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
	}
	else if (nbr < 10)
		ft_putchar((char)nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10 + '0'));
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}