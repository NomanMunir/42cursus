/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:22:20 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/22 21:13:35 by nmunir           ###   ########.fr       */
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
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += put_hex(va_arg(args, unsigned int), c);
	else if (c == 'u')
		count += ft_put_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_put_ptr(va_arg(args, unsigned long long));
	else if (c == '%')
		count += ft_putchar('%');
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
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
// int	main(void)
// {
// 	printf("%d\n", ft_printf("%s\n", NULL));
// 	printf("%d\n", printf("%s\n", NULL));
// 	return (0);
// }
