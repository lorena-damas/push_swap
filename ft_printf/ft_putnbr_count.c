/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 09:23:32 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/09 13:13:01 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_count(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_count(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putunsigned_count(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned_count(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_puthex_count(unsigned long n, char *base)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
		count += ft_puthex_count(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putptr_count(void *ptr)
{
	int	count;

	if (ptr == NULL)
		return (ft_putstr_count("(nil)"));
	count = 0;
	count += ft_putstr_count("0x");
	count += ft_puthex_count((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
