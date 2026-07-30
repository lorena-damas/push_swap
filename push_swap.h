/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:11:38 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/30 16:57:36 by jotto            ###   ########.fr       */
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

typedef struct s_bench
{
	int	bench_active;
	int	total_ops;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

int		check_input(int argc, char **argv, int *values);
int		parse_args(int argc, char **argv, int *values, t_strategy *strategy);
void	adaptive_sort(int *a, int *b, int *na, int *nb);
int		find_min_value(int *values, int count);
int		find_max_value(int *values, int count);
int		*sorted_copy(int *values, int count);
void	sort_array(int *values, int count);
int		get_rank(int *sorted, int count, int value);
//Sorting strategies
void	sort_simple(int *a, int *b, int *na, int *nb);
void	sort_medium(int *a, int *b, int *na, int *nb);
void	sort_complex(int *a, int *b, int *na, int *nb);
//Operation functions
void	op_swap(int *values, int count, char aob);
void	op_push(int *srcstack, int *deststack, int **sizes, char aorbstack);
void	op_rotate(int *values, int count, char aob);
void	op_reverse(int *values, int count, char aob);
int		replace_with_ranks(int *a, int sizea);
//Benchmark



#endif
