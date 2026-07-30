/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_helper_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:12:38 by jotto             #+#    #+#             */
/*   Updated: 2026/07/30 16:57:36 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	bench_record(const char *op)
{
	if (!t_bench.bench_active || op == NULL)
		return ;
	if (ft_strncmp(op, "sa\n", 3) == 0)
		t_bench.sa++;
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		t_bench.sb++;
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		t_bench.ss++;
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		t_bench.pa++;
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		t_bench.pb++;
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		t_bench.ra++;
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		t_bench.rb++;
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		t_bench.rr++;
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		t_bench.rra++;
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		t_bench.rrb++;
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		t_bench.rrr++;
	t_bench.total_ops++;
}

//i think this approach is completly idiotic, i dont know what i was thinking
int bench_extract_args(int argc, char **argv, int *values, t_strategy *strat)
{
	char	**argv2;
	int		i;
	int		j;
	int		sizea;

	argv2 = malloc(sizeof(*argv2) * (size_t)argc);
	if (argv2 == NULL)
		return (-1);
	argv2[0] = argv[0];
	i = 1;
	j = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) != 0)
		{
			argv2[j] = argv[i];
			j++;
		}
		i++;
	}
	sizea = parse_args(j, argv2, values, strat);
	free(argv2);
	return (sizea);
}
