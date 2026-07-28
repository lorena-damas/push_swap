/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:14:08 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/27 19:14:50 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	replace_with_ranks(int *a, int sizea)
{
	int	*sorted;
	int	i;
	int	rank;

	sorted = sorted_copy(a, sizea);
	if (sorted == NULL)
		return (0);
	i = 0;
	while (i < sizea)
	{
		rank = get_rank(sorted, sizea, a[i]);
		if (rank == -1)
		{
			free (sorted);
			return (0);
		}
		a[i] = rank;
		i++;
	}
	free (sorted);
	return (1);
}
