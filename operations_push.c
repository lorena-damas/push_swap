/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:48:45 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 19:48:49 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	push_value(int *src, int *dst, int *src_size, int *dst_size)
{
	int	i;
	int	value;

	value = src[0];
	i = 0;
	while (i < *src_size - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*src_size)--;
	i = *dst_size;
	while (i > 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = value;
	(*dst_size)++;
}

void	op_push(t_data *data, char target)
{
	if (target == 'a' && data->sizeb > 0)
	{
		push_value(data->b, data->a, &data->sizeb, &data->sizea);
		ft_putstr_fd("pa\n", 1);
		bench_record(&data->bench, OP_PA);
	}
	else if (target == 'b' && data->sizea > 0)
	{
		push_value(data->a, data->b, &data->sizea, &data->sizeb);
		ft_putstr_fd("pb\n", 1);
		bench_record(&data->bench, OP_PB);
	}
}
