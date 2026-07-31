/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:02:48 by jotto             #+#    #+#             */
/*   Updated: 2026/07/31 07:51:20 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include "push_swap.h"

// typedef struct s_bench
// {
// 	double	disorder;
// 	int		bench_active;
// 	int		total_ops;
// 	int		sa;
// 	int		sb;
// 	int		ss;
// 	int		pa;
// 	int		pb;
// 	int		ra;
// 	int		rb;
// 	int		rr;
// 	int		rra;
// 	int		rrb;
// 	int		rrr;
// }	t_bench;

void	bench_enable(void);
void	bench_disable(void);
void	bench_record(const char *op);
void	bench_print(double disorder, t_strategy strat);
int		bench_run(int argc, char **argv);
//t_bench *bench_get_metrics(void);
int		bench_extract_args(int argc, char **argv, int *values, t_strategy *strat);
int		bench_is_enabled(void);

#endif
