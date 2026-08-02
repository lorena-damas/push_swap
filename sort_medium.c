/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:35 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 20:00:40 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int count)
{
	int	chunks;

	chunks = 1;
	while ((chunks + 1) * (chunks + 1) <= count)
		chunks++;
	return ((count + chunks - 1) / chunks);
}

static void	push_chunks(t_data *data)
{
	int	chunk_size;
	int	chunk_limit;

	chunk_size = get_chunk_size(data->sizea);
	chunk_limit = chunk_size;
	while (data->sizea > 0)
	{
		if (data->a[0] < chunk_limit)
		{
			op_push(data, 'b');
			if (data->sizeb == chunk_limit)
				chunk_limit += chunk_size;
		}
		else
			op_rotate(data, 'a');
	}
}

static void	move_max_to_top(t_data *data)
{
	int	index;

	index = find_max_value(data->b, data->sizeb);
	if (index <= data->sizeb / 2)
	{
		while (index-- > 0)
			op_rotate(data, 'b');
	}
	else
	{
		while (index++ < data->sizeb)
			op_reverse(data, 'b');
	}
}

void	sort_medium(t_data *data)
{
	if (!replace_with_ranks(data->a, data->sizea))
		return ;
	push_chunks(data);
	while (data->sizeb > 0)
	{
		move_max_to_top(data);
		op_push(data, 'a');
	}
}
