/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:11:38 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/26 20:11:23 by jotto            ###   ########.fr       */
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
} t_strategy;

int		check_input(int argc, char **argv, int *values);
int		parse_args(int argc, char **argv, int *values, t_strategy *strategy);
void	sort_simple(int *a, int *b, int *na, int *nb);
void	sort_medium(int *a, int *b, int *na, int *nb);
void	sort_complex(int *a, int *b, int *na, int *nb);
void	adaptive_sort(int *a, int *b, int *na, int *nb);
int		find_min_value(int *values, int count);
int		find_max_value(int *values, int count);
int		*sorted_copy(int *values, int count);
void	sort_array(int *values, int count);
int		get_rank(int *sorted, int count, int value);
//Operation functions
void	op_swap(int *values, int count, char id);
void	op_push(int *from, int *to, int *nfrom, int *nto, char id);
void	op_rotate(int *values, int count, char id);
void	op_reverse(int *values, int count, char id);

#endif
