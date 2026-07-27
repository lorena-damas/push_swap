/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 09:24:01 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/09 13:09:45 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_count(char *s)
{
	int	j;
	int	count;

	if (s == NULL)
		return (ft_putstr_count("(null)"));
	j = 0;
	count = 0;
	while (s[j])
	{
		count += ft_putchar_count(s[j]);
		j++;
	}
	return (count);
}
