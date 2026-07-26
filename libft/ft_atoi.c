/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:15:41 by jotto             #+#    #+#             */
/*   Updated: 2026/06/12 01:58:58 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus_sign;
	int	result;

	minus_sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\r'
		|| nptr[i] == '\f' || nptr[i] == '\v' || nptr[i] == '\n')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus_sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = 10 * result + (nptr[i] - '0');
		i++;
	}
	result *= minus_sign;
	return (result);
}

/*int	main(void)
{
	printf("TEST 1:%d\n", ft_atoi(" 	\t\r\f\v\n++++-+---+123"));
	printf("TEST 2:%d\n", ft_atoi("--1234"));
	printf("TEST 3:%d\n", ft_atoi("++++12345"));
	printf("TEST 4:%d\n", ft_atoi("-123456"));
}*/