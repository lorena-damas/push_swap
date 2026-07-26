/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:12 by jotto             #+#    #+#             */
/*   Updated: 2026/07/25 14:41:12 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

void	op_swap(int *values, int count, char id);
void	op_push(int *from, int *to, int *nfrom, int *nto, char id);
void	op_rotate(int *values, int count, char id);
void	op_reverse(int *values, int count, char id);

#endif
