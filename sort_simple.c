/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:40 by jotto             #+#    #+#             */
/*   Updated: 2026/07/26 21:32:04 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(int *a, int *b, int *sizea, int *sizeb)
{
	int	index;
	int	count;

	count = *sizea;
	while (*sizea > 0)
	{
		index = find_min_value(a, *sizea);
		if (index <= *sizea / 2)
		{
			while (index > 0)
			{
				op_rotate(a, *sizea, 'a');
				index--;
			}
		}
		else
		{
			while (index < *sizea)
			{
				op_reverse(a, *sizea, 'a');
				index++;
			}
		}
		op_push(a, b, sizea, sizeb, 'b');
	}
	while (*sizeb > 0)
		op_push(b, a, sizeb, sizea, 'a');
	*sizea = count;
}
