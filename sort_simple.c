/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:40 by jotto             #+#    #+#             */
/*   Updated: 2026/07/27 10:49:58 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(int *a, int sizea)
{
	int	index;

	index = find_min_value(a, sizea);
	if (index <= sizea / 2)
	{
		while (index-- > 0)
			op_rotate(a, sizea, 'a');
	}
	else
	{
		while (index++ < sizea)
			op_reverse(a, sizea, 'a');
	}
}

void	sort_simple(int *a, int *b, int *sizea, int *sizeb)
{
	int	*sizes[2];

	sizes[0] = sizea;
	sizes[1] = sizeb;
	while (*sizea > 0)
	{
		move_min_to_top(a, *sizea);
		op_push(a, b, sizes, 'b');
	}
	sizes[0] = sizeb;
	sizes[1] = sizea;
	while (*sizeb > 0)
		op_push(b, a, sizes, 'a');
}
