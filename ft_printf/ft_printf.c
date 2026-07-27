/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:33:57 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/09 13:01:10 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_is_conversion(char c)
{
	if (c == 'd' || c == 'i' || c == '%' || c == 'c'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

static int	ft_handle_format(char type, va_list *args)
{
	char	c;

	if (type == 'd' || type == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	if (type == '%')
		return (ft_putchar_count('%'));
	if (type == 'c')
	{
		c = va_arg(*args, int);
		return (ft_putchar_count(c));
	}
	if (type == 's')
		return (ft_putstr_count(va_arg(*args, char *)));
	if (type == 'u')
		return (ft_putunsigned_count(va_arg(*args, unsigned int)));
	if (type == 'x')
		return (ft_puthex_count(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	if (type == 'X')
		return (ft_puthex_count(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	if (type == 'p')
		return (ft_putptr_count(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_is_conversion(format[i + 1]))
		{
			count += ft_handle_format(format[i + 1], &args);
			i += 2;
		}
		else
		{
			count += ft_putchar_count(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}


