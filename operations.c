/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:40:59 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 19:51:38 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	get_stack(t_data *data, char a_or_b, int **stack, int *size)
{
	if (a_or_b == 'a')
	{
		*stack = data->a;
		*size = data->sizea;
	}
	else
	{
		*stack = data->b;
		*size = data->sizeb;
	}
}

static void	process_op(t_data *data, char *a_or_b, t_op op)
{
	ft_putstr_fd(a_or_b, 1);
	bench_record(&data->bench, op);
}

void	op_swap(t_data *data, char a_or_b)
{
	int	*stack;
	int	size;
	int	tmp;

	get_stack(data, a_or_b, &stack, &size);
	if (size < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (a_or_b == 'a')
		process_op(data, "sa\n", OP_SA);
	else
		process_op(data, "sb\n", OP_SB);
}

void	op_rotate(t_data *data, char a_or_b)
{
	int	*stack;
	int	size;
	int	first;
	int	i;

	get_stack(data, a_or_b, &stack, &size);
	if (size < 2)
		return ;
	first = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = first;
	if (a_or_b == 'a')
		process_op(data, "ra\n", OP_RA);
	else
		process_op(data, "rb\n", OP_RB);
}

void	op_reverse(t_data *data, char a_or_b)
{
	int	*stack;
	int	size;
	int	last;
	int	i;

	get_stack(data, a_or_b, &stack, &size);
	if (size < 2)
		return ;
	last = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
	if (a_or_b == 'a')
		process_op(data, "rra\n", OP_RRA);
	else
		process_op(data, "rrb\n", OP_RRB);
}
