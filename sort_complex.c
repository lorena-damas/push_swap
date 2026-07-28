/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:42:27 by jotto             #+#    #+#             */
/*   Updated: 2026/07/27 19:58:10 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int sizea)
{
	int	max_value;
	int	bits;

	max_value = sizea - 1;
	bits = 0;
	while (max_value > 0)
	{
		max_value = max_value >> 1;
		bits++;
	}
	return (bits);
}

// Ex: 99
// in Binarie 1100011
// The function does:
// 99 >> 1 = 49
// 49 >> 1 = 24
// 24 >> 1 = 12
// 12 >> 1 = 6
// 6 >> 1 = 3
// 3 >> 1 = 1
// 1 >> 1 = 0
// bits == 7

static void	sort_one_bit(int *a, int *b, int **sizes, int bit)
{
	int	count;

	count = *sizes[0];
	while (count > 0)
	{
		if (((a[0] >> bit) & 1) == 0)
			op_push(a, b, sizes, 'b');
		else
			op_rotate(a, *sizes[0], 'a');
		count--;
	}
}

static void	return_to_a(int *a, int *b, int **sizes)
{
	int	*reverse_sizes[2];

	reverse_sizes[0] = sizes[1];
	reverse_sizes[1] = sizes[0];
	while (*sizes[1] > 0)
		op_push(b, a, reverse_sizes, 'a');
}

void	sort_complex(int *a, int *b, int *sizea, int *sizeb)
{
	int	bit;
	int	max_bits;
	int	*sizes[2];

	if (!replace_with_ranks(a, *sizea))
		return ;
	max_bits = get_max_bits(*sizea);
	sizes[0] = sizea;
	sizes[1] = sizeb;
	bit = 0;
	while (bit < max_bits)
	{
		sort_one_bit(a, b, sizes, bit);
		return_to_a(a, b, sizes);
		bit++;
	}
}
