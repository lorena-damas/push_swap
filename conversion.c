/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:11:47 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/15 19:32:25 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	str_to_int(char *str, int *value)
{
	long long	result;
	long long	limit;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (sign == -1)
		limit = -(long long)INT_MIN;
	else
		limit = INT_MAX;
	while (str[i] != '\0')
	{
		if (result > (limit - (str[i] - '0')) / 10)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	*value = (int)(result * sign);
	return (1);
}
