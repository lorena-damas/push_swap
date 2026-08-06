/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:30:20 by lordamas          #+#    #+#             */
/*   Updated: 2026/08/06 08:25:26 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int	prepare_data(int argc, char **argv, t_data *data,
		t_options *options)
{
	data->a = malloc((argc - 1) * sizeof(*data->a));
	if (data->a == NULL)
		return (0);
	data->sizea = parse_args(argc, argv, data->a, options);
	if (data->sizea == 0)
	{
		write(2, "Error\n", 6);
		free(data->a);
		return (0);
	}
	data->b = malloc(data->sizea * sizeof(*data->b));
	if (data->b == NULL)
	{
		free(data->a);
		return (0);
	}
	data->sizeb = 0;
	bench_init(&data->bench, options->bench);
	return (1);
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

static void	run_sort(t_strategy strategy, t_data *data)
{
	if (is_sorted(data->a, data->sizea))
		return ;
	if (strategy == SIMPLE)
		sort_simple(data);
	else if (strategy == MEDIUM)
		sort_medium(data);
	else if (strategy == COMPLEX)
		sort_complex(data);
}

static void	free_data(t_data *data)
{
	free(data->b);
	free(data->a);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_options	options;
	t_strategy	sort_strategy;
	double		disorder;

	if (argc < 2)
		return (0);
	if (!prepare_data(argc, argv, &data, &options))
		return (1);
	disorder = compute_disorder(data.a, data.sizea);
	sort_strategy = options.strategy;
	if (sort_strategy == ADAPTIVE)
		sort_strategy = adaptive_strategy(disorder);
	run_sort(sort_strategy, &data);
	bench_print(disorder, options.strategy, sort_strategy, &data.bench);
	free_data(&data);
	return (0);
}
