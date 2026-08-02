/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:43:16 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 22:06:47 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	print_disorder(double disorder)
{
	int	scaled;

	scaled = (int)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder:\t", 2);
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
	ft_putstr_fd("[bench] strategy:\t", 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n sqrt(n))", 2);
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
	print_count("[bench] sa:\t", bench->ops[OP_SA], "\t");
	ft_putstr_fd("\n", 2);
	print_count("sb:\t", bench->ops[OP_SB], "\t");
	print_count("ss:\t", bench->ops[OP_SS], "\t");
	print_count("pa:\t", bench->ops[OP_PA], "\t");
	print_count("pb:\t", bench->ops[OP_PB], "\n");
	print_count("[bench] ra:\t", bench->ops[OP_RA], "\t");
	print_count("rb:\t", bench->ops[OP_RB], "\t");
	print_count("rr:\t", bench->ops[OP_RR], "\t");
	print_count("rra:\t", bench->ops[OP_RRA], "\t");
	print_count("rrb:\t", bench->ops[OP_RRB], "\t");
	print_count("rrr:\t", bench->ops[OP_RRR], "\n");
}

void	bench_print(double disorder, t_strategy strategy, t_bench *bench)
{
	if (bench == NULL || !bench->enabled)
		return ;
	print_disorder(disorder);
	print_strategy(strategy);
	print_count("[bench] total_ops:\t", bench->total_ops, "\n");
	print_operation_counts(bench);
}
