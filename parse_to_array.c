/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:42:35 by lordamas          #+#    #+#             */
/*   Updated: 2026/08/03 08:10:14 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	get_strategy(char *arg, t_strategy *strategy)
{
	if (ft_strncmp(arg, "--simple", 9) == 0 && arg[8] == '\0')
		*strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0 && arg[8] == '\0')
		*strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0 && arg[9] == '\0')
		*strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0 && arg[10] == '\0')
		*strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	get_option(char *arg, t_options *options)
{
	if (ft_strncmp(arg, "--bench", 8) == 0
		&& arg[7] == '\0')
	{
		options->bench = 1;
		return (1);
	}
	return (get_strategy(arg, &options->strategy));
}

static int	fill_copy(int argc, char **argv, char **copy, t_options *options)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	copy[0] = argv[0];
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!get_option(argv[i], options))
				return (0);
		}
		else
			copy[count++] = argv[i];
		i++;
	}
	return (count);
}

int	parse_args(int argc, char **argv, int *values, t_options *options)
{
	char	**copy;
	int		count;

	options->strategy= ADAPTIVE;
	options->bench = 0;
	copy = malloc(argc * sizeof(*copy));
	if (copy == NULL)
		return (0);
	count = fill_copy(argc, argv, copy, options);
	if ((count <= 1) || (!check_input(count, copy, values)))
	{
		free(copy);
		return (0);
	}
	free(copy);
	return (count - 1);
}
