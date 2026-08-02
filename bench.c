/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:02:29 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 19:43:58 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "libft.h"

void	bench_init(t_bench *bench, int enabled)
{
	ft_bzero(bench, sizeof(*bench));
	bench->enabled = enabled;
}

void	bench_record(t_bench *bench, t_op op)
{
	if (bench == NULL || !bench->enabled)
		return ;
	if (op < OP_SA || op >= OP_COUNT)
		return ;
	bench->ops[op]++;
	bench->total_ops++;
}
