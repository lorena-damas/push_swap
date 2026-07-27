/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:30:20 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/27 10:44:09 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int	prepare_values(int argc, char **argv, int **values,
		t_strategy *strategy)
{
	int	sizea;

	*values = malloc((argc - 1) * sizeof(**values));
	if (*values == NULL)
		return (-1);
	sizea = parse_args(argc, argv, *values, strategy);
	if (sizea == 0)
	{
		write(2, "Error\n", 6);
		free(*values);
		return (-1);
	}
	return (sizea);
}

static void	run_sort(t_strategy strategy, int *a, int *b, int sizea)
{
	int	sizeb;

	sizeb = 0;
	if (strategy == SIMPLE)
		sort_simple(a, b, &sizea, &sizeb);
	else if (strategy == MEDIUM)
		sort_medium(a, b, &sizea, &sizeb);
	else if (strategy == COMPLEX)
		sort_complex(a, b, &sizea, &sizeb);
	else
		adaptive_sort(a, b, &sizea, &sizeb);
}

int	main(int argc, char **argv)
{
	int			*values;
	int			*b;
	int			sizea;
	t_strategy	strategy;

	if (argc < 2)
		return (0);
	sizea = prepare_values(argc, argv, &values, &strategy);
	if (sizea == -1)
		return (1);
	b = malloc(sizea * sizeof(*b));
	if (b == NULL)
	{
		free(values);
		return (1);
	}
	run_sort(strategy, values, b, sizea);
	free (b);
	free (values);
	return (0);
}
