/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:29 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 19:56:25 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *a, int count)
{
	long long	mistakes;
	long long	total;
	int			i;
	int			j;

	mistakes = 0;
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	total = ((long long)count * (count - 1)) / 2;
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}

t_strategy	adaptive_strategy(double disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}
