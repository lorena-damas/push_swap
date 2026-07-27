/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:41:12 by jotto             #+#    #+#             */
/*   Updated: 2026/07/27 07:31:01 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

void	op_swap(int *values, int count, char id);
void	op_push(int *srcstack, int *deststack, int **sizes,
			char aorbstack);
void	op_rotate(int *values, int count, char id);
void	op_reverse(int *values, int count, char id);

#endif
