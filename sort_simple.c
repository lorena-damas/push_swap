/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:40 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 20:01:01 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_data *data)
{
	int	index;

	index = find_min_value(data->a, data->sizea);
	if (index <= data->sizea / 2)
	{
		while (index-- > 0)
			op_rotate(data, 'a');
	}
	else
	{
		while (index++ < data->sizea)
			op_reverse(data, 'a');
	}
}

void	sort_simple(t_data *data)
{
	while (data->sizea > 0)
	{
		move_min_to_top(data);
		op_push(data, 'b');
	}
	while (data->sizeb > 0)
		op_push(data, 'a');
}
