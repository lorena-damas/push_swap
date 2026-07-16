/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:30:20 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/16 17:15:24 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	*values;
	int	count;

	if (argc < 2)
		return (0);
	count = argc - 1;
	values = malloc(count * sizeof(*values));
	if (values == NULL)
		return (1);
	if (!check_input(argc, argv, values))
	{
		write(2, "Error\n", 6);
		free(values);
		return (1);
	}
	/*
		Stacks A e B.
	*/
	free(values);
	return (0);
}
