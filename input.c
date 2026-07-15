/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:15:27 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/15 19:32:44 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_and_convert(int argc, char **argv, int *values)
{
	int	i;
	int	number;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		if (!str_to_int(argv[i], &number))
			return (0);
		values[i - 1] = number;
		i++;
	}
	return (1);
}
