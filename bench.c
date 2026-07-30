/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:02:29 by jotto             #+#    #+#             */
/*   Updated: 2026/07/30 13:57:44 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static	t_bench	t_bench;
static	int	t_bench.bench_active = 0;




void	bench_enable(void)
{
	ft_bzero(&t_bench, sizeof(t_bench));
	t_bench.bench_active = 1;
}

void	bench_disable(void)
{
	t_bench.bench_active = 0;
}

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

int	bench_run(int argc, char **argv)
{
	int			*values;
	int			sizea;
	t_strategy	strat;
	double		disorder;
	int			*b;
	int			sizeb;

	if (argc < 2)
		return (0);
	values = malloc((argc - 1) * sizeof(*values));
	if (values == NULL)
		return (1);
	sizea = bench_extract_args(argc, argv, values, &strat);
	if (sizea == -1)
	{
		free(values);
		return (1);
	}
	if (sizea == 0)
	{
		free(values);
		write(2, "Error\n", 6);
		return (1);
	}
	disorder = compute_disorder(values, sizea);
	bench_enable();
	b = malloc(sizea * sizeof(*b));
	if (b == NULL)
	{
		free(values);
		return (1);
	}
	sizeb = 0;
	run_sort(strat, values, b, &sizea, &sizeb);
	bench_print(disorder, strat);
	bench_disable();
	free(b);
	free(values);
	return (0);
}
