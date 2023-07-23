/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:22:20 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/23 18:34:56 by nmunir           ###   ########.fr       */
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
		count += ft_putnbr((long)va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += put_hex(va_arg(args, unsigned int), c);
	else if (c == 'u')
		count += ft_put_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_put_ptr(va_arg(args, uintptr_t));
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

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned int	unsignedint;

// 	unsignedint = -1;
// 	ft_printf("\n\n\nif string is NULL:\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %s\n", NULL));
// 	printf("Count:%d	\n", printf("printf : %s\n", NULL));
// 	ft_printf("\n For Case %%s :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %s\n", "Hello World"));
// 	printf("Count:%d	\n", printf("printf: %s\n", "Hello World"));
// 	ft_printf("\n For Case %%d :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %d\n", 2147483));
// 	printf("Count:%d	\n", printf("printf: %d\n", 2147483));
// 	ft_printf("\n For Case %%i :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %i\n", 2147483));
// 	printf("Count:%d	\n", printf("printf: %i\n", 2147483));
// 	ft_printf("\n For Case %%x :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %x\n", -2147483));
// 	printf("Count:%d	\n", printf("printf: %x\n", -2147483));
// 	ft_printf("\n For Case %%X :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %X\n", 2147483));
// 	printf("Count:%d	\n", printf("printf: %X\n", 2147483));
// 	ft_printf("\n For Case %%u :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %u\n", unsignedint));
// 	printf("Count:%d	\n", printf("printf: %u\n", unsignedint));
// 	ft_printf("\n For Case %%p :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %p\n", &unsignedint));
// 	printf("Count:%d	\n", printf("printf: %p\n", &unsignedint));
// 	ft_printf("\n For Case %% :\n");
// 	ft_printf("Count:%d	\n", ft_printf("ftprintf: %%\n"));
// 	printf("Count:%d	\n", printf("printf: %%\n"));
// 	return (0);
// }
