/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:02:48 by jotto             #+#    #+#             */
/*   Updated: 2026/08/02 19:44:27 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include "push_swap.h"

void	bench_init(t_bench *bench, int enabled);
void	bench_record(t_bench *bench, t_op op);
void	bench_print(double disorder, t_strategy strategy, t_bench *bench);

#endif
