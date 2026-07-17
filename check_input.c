/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:15:27 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/17 09:32:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(int *values, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long long	f_limit(int sign)
{
	long long	limit;

	if (sign == -1)
		limit = -(long long)INT_MIN;
	else
		limit = INT_MAX;
	return (limit);
}

static int	str_to_int(char *str, int *value)
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
	limit = f_limit(sign);
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

int	check_input(int argc, char **argv, int *values)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		if (!str_to_int(argv[i], &values[i - 1]))
			return (0);
		i++;
	}
	if (has_duplicates(values, argc - 1))
		return (0);
	return (1);
}
