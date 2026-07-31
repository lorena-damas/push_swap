/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:29 by jotto             #+#    #+#             */
/*   Updated: 2026/07/31 07:51:50 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *a, int count)
{
	int		mistakes;
	int		total;
	int		i;
	int		j;
	double	disorder;

	mistakes = 0;
	total = 0;
	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (a[i] > a[j])
				mistakes++;
			total++;
			j++;
		}
		i++;
	}
	if (total == 0)
		return (0.0);
	disorder = (double)mistakes / (double)total;
	return (disorder);
}

void	adaptive_sort(int *a, int *b, int *sizea, int *sizeb)
{
	double	disorder;

	disorder = compute_disorder(a, *sizea);
	if (disorder < 0.2)
		sort_simple(a, b, sizea, sizeb);
	else if (disorder < 0.5)
		sort_medium(a, b, sizea, sizeb);
	else
		sort_complex(a, b, sizea, sizeb);
}
