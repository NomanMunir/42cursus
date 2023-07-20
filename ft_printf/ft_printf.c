/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:22:20 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/20 20:06:34 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char c, va_list args)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
	{
		count += ft_putnbr(va_arg(args, int));
	}
	// else if (c == 'u')
	// 	count += (va_arg(args, unsigned int ));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	count;
	int	count_for_print;

	count = ft_printf("Hello %i \n", 1548153);
	printf("%i\n", count);
	count_for_print = printf("Hello %i \n", 1578533);
	printf("%i", count_for_print);
	return (0);
}
