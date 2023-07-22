/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:26:31 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/22 20:49:24 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_putchar(int c);
int		ft_putnbr(int nbr);
char	*ft_itoa(long n);
int		put_hex(unsigned int num, const char format);
int		ft_put_unsigned_int(unsigned int n);
int		ft_put_ptr(unsigned long long ptr);

#endif