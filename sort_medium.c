/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:35 by jotto             #+#    #+#             */
/*   Updated: 2026/07/27 17:58:51 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	get_chunk_size(int count)
{
	int	chunks;

	chunks = 1;
	while ((chunks + 1) * (chunks + 1) <= count)
		chunks++;
	return ((count + chunks - 1) / chunks);
}

static int	replace_with_ranks(int *a, int sizea)
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

static void	push_chunks(int *a, int *b, int *sizea, int *sizeb)
{
	int	chunk_size;
	int	chunk_limit;
	int	*sizes[2];

	chunk_size = get_chunk_size(*sizea);
	chunk_limit = chunk_size;
	sizes[0] = sizea;
	sizes[1] = sizeb;
	while (*sizea > 0)
	{
		if (a[0] < chunk_limit)
		{
			op_push(a, b, sizes, 'b');
			if (*sizeb == chunk_limit)
				chunk_limit += chunk_size;
		}
		else
			op_rotate(a, *sizea, 'a');
	}
}

static void	move_max_to_top(int *b, int sizeb)
{
	int	index;

	index = find_max_value(b, sizeb);
	if (index <= sizeb / 2)
	{
		while (index-- > 0)
			op_rotate(b, sizeb, 'b');
	}
	else
	{
		while (index++ < sizeb)
			op_reverse(b, sizeb, 'b');
	}
}

void	sort_medium(int *a, int *b, int *sizea, int *sizeb)
{
	int	*sizes[2];

	if (!replace_with_ranks(a, *sizea))
		return ;
	push_chunks(a, b, sizea, sizeb);
	sizes[0] = sizeb;
	sizes[1] = sizea;
	while (*sizeb > 0)
	{
		move_max_to_top(b, *sizeb);
		op_push(b, a, sizes, 'a');
	}
}
