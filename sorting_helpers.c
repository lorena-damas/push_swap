/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:40:51 by jotto             #+#    #+#             */
/*   Updated: 2026/07/27 18:30:31 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	find_min_value(int *values, int count)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = values[0];
	j = 1;
	while (j < count)
	{
		if (values[j] < min)
		{
			min = values[j];
			i = j;
		}
		j++;
	}
	return (i);
}

int	find_max_value(int *values, int count)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = values[0];
	j = 1;
	while (j < count)
	{
		if (values[j] > max)
		{
			max = values[j];
			i = j;
		}
		j++;
	}
	return (i);
}

int	*sorted_copy(int *values, int count)
{
	int	*copy;
	int	i;

	copy = malloc(count * sizeof(*copy));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		copy[i] = values[i];
		i++;
	}
	sort_array(copy, count);
	return (copy);
}

void	sort_array(int *values, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] > values[j])
			{
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_rank(int *sorted, int count, int value)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
