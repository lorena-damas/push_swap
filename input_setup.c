/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:44:02 by lordamas          #+#    #+#             */
/*   Updated: 2026/08/09 21:44:02 by lordamas         ###   ########.fr       */
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

int	prepare_input(int argc, char **argv, t_data *data,
		t_options *options)
{
	t_input	input;

	if (!expand_args(argc, argv, &input))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!prepare_data(input.argc, input.argv, data, options))
	{
		free_expanded_args(&input);
		return (0);
	}
	free_expanded_args(&input);
	return (1);
}
