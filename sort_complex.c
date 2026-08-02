/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:42:27 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 19:59:07 by jotto            ###   ########.fr       */
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

static void	sort_one_bit(t_data *data, int bit)
{
	int	count;

	count = data->sizea;
	while (count > 0)
	{
		if (((data->a[0] >> bit) & 1) == 0)
			op_push(data, 'b');
		else
			op_rotate(data, 'a');
		count--;
	}
}

static void	return_to_a(t_data *data)
{
	while (data->sizeb > 0)
		op_push(data, 'a');
}

void	sort_complex(t_data *data)
{
	int	bit;
	int	max_bits;

	if (!replace_with_ranks(data->a, data->sizea))
		return ;
	max_bits = get_max_bits(data->sizea);
	bit = 0;
	while (bit < max_bits)
	{
		sort_one_bit(data, bit);
		return_to_a(data);
		bit++;
	}
}
