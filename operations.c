/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:40:59 by jotto             #+#    #+#             */
/*   Updated: 2026/07/25 14:40:59 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	op_swap(int *values, int count, char aorbstack)
{
	int	tmp;

	if (count < 2)
		return;
	tmp = values[0];
	values[0] = values[1];
	values[1] = tmp;
	if (aorbstack == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	op_push(int *from, int *to, int *nfrom, int *nto, char aorbstack)
{
	int	i;
	int	value;

	if (*nfrom == 0)
		return;
	value = from[0];
	i = 0;
	while (i < *nfrom - 1)
	{
		from[i] = from[i + 1];
		i++;
	}
	(*nfrom)--;
	i = *nto;
	while (i > 0)
	{
		to[i] = to[i - 1];
		i--;
	}
	to[0] = value;
	(*nto)++;
	if (aorbstack == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	op_rotate(int *values, int count, char aorbstack)
{
	int	i;
	int	first;

	if (count < 2)
		return;
	first = values[0];
	i = 0;
	while (i < count - 1)
	{
		values[i] = values[i + 1];
		i++;
	}
	values[count - 1] = first;
	if (aorbstack == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	op_reverse(int *values, int count, char aorbstack)
{
	int	i;
	int	last;

	if (count < 2)
		return;
	last = values[count - 1];
	i = count - 1;
	while (i > 0)
	{
		values[i] = values[i - 1];
		i--;
	}
	values[0] = last;
	if (aorbstack == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
