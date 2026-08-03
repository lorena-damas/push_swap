/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:43:16 by jotto             #+#    #+#             */
/*   Updated: 2026/08/03 08:44:19 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	print_disorder(double disorder)
{
	int	scaled;

	scaled = (int)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(scaled / 100, 2);
	ft_putchar_fd('.', 2);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(scaled % 100, 2);
	ft_putstr_fd("%", 2);
	ft_putstr_fd("\n", 2);
}

static void	print_strategy(t_strategy strategy)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else
		ft_putstr_fd("Adaptive / O(n√n)", 2);
	ft_putstr_fd("\n", 2);
}

static void	print_count(char *pretext, int value, char *end_tab)
{
	ft_putstr_fd(pretext, 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd(end_tab, 2);
}

static void	print_operation_counts(t_bench *bench)
{
	print_count("[bench] sa: ", bench->ops[OP_SA], " ");
	print_count("sb: ", bench->ops[OP_SB], " ");
	print_count("ss: ", bench->ops[OP_SS], " ");
	print_count("pa: ", bench->ops[OP_PA], " ");
	print_count("pb: ", bench->ops[OP_PB], "\n");
	print_count("[bench] ra: ", bench->ops[OP_RA], " ");
	print_count("rb: ", bench->ops[OP_RB], " ");
	print_count("rr: ", bench->ops[OP_RR], " ");
	print_count("rra: ", bench->ops[OP_RRA], " ");
	print_count("rrb: ", bench->ops[OP_RRB], " ");
	print_count("rrr: ", bench->ops[OP_RRR], "\n");
}

void	bench_print(double disorder, t_strategy strategy, t_bench *bench)
{
	if (bench == NULL || !bench->enabled)
		return ;
	print_disorder(disorder);
	print_strategy(strategy);
	print_count("[bench] total_ops: ", bench->total_ops, "\n");
	print_operation_counts(bench);
}
