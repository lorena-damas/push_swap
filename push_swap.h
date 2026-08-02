/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:11:38 by lordamas          #+#    #+#             */
/*   Updated: 2026/08/02 22:10:39 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef enum e_operations
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_bench
{
	int	enabled;
	int	total_ops;
	int	ops[OP_COUNT];
}	t_bench;

typedef struct s_data
{
	int		*a;
	int		*b;
	int		sizea;
	int		sizeb;
	t_bench	bench;
}	t_data;

//Input Validation
int			check_input(int argc, char **argv, int *values);
int			parse_args(int argc, char **argv, int *values, t_strategy *strategy, int *bench);
// Strategy
t_strategy	adaptive_strategy(double disorder);
double		compute_disorder(int *a, int count);
void		sort_simple(t_data *data);
void		sort_medium(t_data *data);
void		sort_complex(t_data *data);
// Operations
void		op_swap(t_data *data, char stack);
void		op_push(t_data *data, char target);
void		op_rotate(t_data *data, char stack);
void		op_reverse(t_data *data, char stack);
int			replace_with_ranks(int *a, int sizea);
// Helper Functions (Sorting)
int			find_min_value(int *values, int count);
int			find_max_value(int *values, int count);
int			*sorted_copy(int *values, int count);
void		sort_array(int *values, int count);
int			get_rank(int *sorted, int count, int value);
// Benchmark
void		bench_init(t_bench *bench, int enabled);
void		bench_record(t_bench *bench, t_op op);
void		bench_print(double disorder, t_strategy strategy, t_bench *bench);

#endif
