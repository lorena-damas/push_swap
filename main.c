/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:30:20 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/27 14:00:27 by lordamas         ###   ########.fr       */
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

static int	is_sorted(int *a, int sizea)
{
	int	i;

	i = 0;
	while (i < sizea - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	run_sort(t_strategy strategy, int *a, int *b, int sizea)
{
	int	sizeb;

	if (is_sorted(a, sizea))
		return ;
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
