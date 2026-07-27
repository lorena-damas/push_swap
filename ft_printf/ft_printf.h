/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:33:51 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/09 13:00:45 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_count(char c);
int	ft_putnbr_count(int n);
int	ft_putstr_count(char *s);
int	ft_putunsigned_count(unsigned int n);
int	ft_puthex_count(unsigned long n, char *base);
int	ft_putptr_count(void *ptr);

#endif
