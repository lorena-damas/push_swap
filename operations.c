/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:40:59 by jotto             #+#    #+#             */
/*   Updated: 2026/07/27 09:43:22 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	op_swap(int *values, int count, char aorb)
{
	int	tmp;

	if (count < 2)
		return ;
	tmp = values[0];
	values[0] = values[1];
	values[1] = tmp;
	if (aorb == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	op_push(int *src, int *dest, int *sizesrc, int *sizedest, char aorb)
{
	int	i;
	int	value;

	if (*sizesrc == 0)
		return ;
	value = src[0];
	i = 0;
	while (i < *sizesrc - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	*sizesrc -= 1;
	i = *sizedest;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = value;
	*sizedest += 1;
	if (aorb == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	op_rotate(int *values, int count, char aorb)
{
	int	i;
	int	first;

	if (count < 2)
		return ;
	first = values[0];
	i = 0;
	while (i < count - 1)
	{
		values[i] = values[i + 1];
		i++;
	}
	values[count - 1] = first;
	if (aorb == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	op_reverse(int *values, int count, char aorb)
{
	int	i;
	int	last;

	if (count < 2)
		return ;
	last = values[count - 1];
	i = count - 1;
	while (i > 0)
	{
		values[i] = values[i - 1];
		i--;
	}
	values[0] = last;
	if (aorb == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
