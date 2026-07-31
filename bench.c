/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:02:29 by jotto             #+#    #+#             */
/*   Updated: 2026/07/31 07:16:43 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	print_strategy(t_strategy strat)
{
	ft_putstr_fd("[bench] strategy:\t", 2);
	if (strat == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (strat == MEDIUM)
		ft_putstr_fd("Medium / O(n log n)\n", 2);
	else if (strat == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n\u221An)\n", 2);
}

static void	print_disorder(double disorder)
{
	int	value;
	int	integer_part;
	int	decimal_part;

	ft_putstr_fd("[bench] disorder:\t", 2);
	value = (int)(disorder * 10000 + 0.5);
	integer_part = value / 100;
	decimal_part = value % 100;
	write(2, "Disorder: ", 10);
	put_number_fd(integer_part, 2);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	put_number_fd(decimal_part, 2);
	write(2, "%\n", 2);
}

static void	print_op_count(t_bench ops_count)
{
	ft_putstr_fd("[bench] total_ops:\t", 2);
	ft_putnbr_fd(t_bench.total_ops, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa:\t", 2);
	ft_putnbr_fd(t_bench.sa, 2);
	ft_putstr_fd("\tsb:\t", 2);
	ft_putnbr_fd(t_bench.sb, 2);
	ft_putstr_fd("\tss:\t", 2);
	ft_putnbr_fd(t_bench.ss, 2);
	ft_putstr_fd("\tpa:\t", 2);
	ft_putnbr_fd(t_bench.pa, 2);
	ft_putstr_fd("\tpb:\t", 2);
	ft_putnbr_fd(t_bench.pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra:\t", 2);
	ft_putnbr_fd(t_bench.ra, 2);
	ft_putstr_fd("\trb:\t", 2);
	ft_putnbr_fd(t_bench.rb, 2);
	ft_putstr_fd("\trr:\t", 2);
	ft_putnbr_fd(t_bench.rr, 2);
	ft_putstr_fd("\trra:\t", 2);
	ft_putnbr_fd(t_bench.rra, 2);
	ft_putstr_fd("\trrb:\t", 2);
	ft_putnbr_fd(t_bench.rrb, 2);
	ft_putstr_fd("\trrr:\t", 2);
	ft_putnbr_fd(t_bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	bench_print(double disorder, t_strategy strat, t_bench ops_count)
{
	t_bench *t_bench;

	print_disorder(disorder);
	print_strategy(strat);
	print_op_count(ops_count);
}

int	init_benchmode(double disorder, t_strategy strat, t_bench ops_count)
{
	if	t_bench	bench_active = 1;
	bench_print
}
