/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:11:38 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/15 19:32:20 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int	is_valid_number(char *str);
int	str_to_int(char *str, int *value);
int	validate_and_convert(int argc, char **argv, int *values);
int	has_duplicates(int *values, int count);

#endif
