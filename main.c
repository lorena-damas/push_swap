/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:30:20 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/26 14:16:39 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int			*values;
	int			*a;
	int			*b;
	int			sizea;
	int			sizeb;
	t_strategy	strategy;

	if (argc < 2)
		return (0);
	values = malloc((argc - 1) * sizeof(*values));
	if (values == NULL)
		return (1);
	if (!parse_args(argc, argv, values, &strategy))
	{
		write(2, "Error\n", 6);
		free(values);
		return (1);
	}
	sizea = argc - 1;
	a = values;
	b = malloc(sizea * sizeof(*b));
	if (b == NULL)
	{
		free(values);
		return (1);
	}
	sizeb = 0;
	if (strategy == SIMPLE)
		sort_simple(a, b, &sizea, &sizeb);
	else if (strategy == MEDIUM)
		sort_medium(a, b, &sizea, &sizeb);
	else if (strategy == COMPLEX)
		sort_complex(a, b, &sizea, &sizeb);
	else
		adaptive_sort(a, b, &sizea, &sizeb);
	free(b);
	free(values);
	return (0);
}
