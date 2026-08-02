/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:42:35 by lordamas          #+#    #+#             */
/*   Updated: 2026/08/02 22:21:12 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	get_strategy(char *arg, t_strat *strategy)
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

static int	fill_copy(int argc, char **argv, char **copy, t_strat *strategy, int *bench)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	copy[0] = argv[0];
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0
			&& argv[i][7] == '\0')
			*bench = 1;
		else if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!get_strat(argv[i], strategy))
				return (0);
		}
		else
			copy[count++] = argv[i];
		i++;
	}
	return (count);
}

int	parse_args(int argc, char **argv, int *values, t_strat *strategy,
		int *bench)
{
	char	**copy;
	int		count;

	*strategy = ADAPTIVE;
	*bench = 0;
	copy = malloc(argc * sizeof(*copy));
	if (copy == NULL)
		return (0);
	count = fill_copy(argc, argv, copy, strategy, bench);
	if ((count <= 1) || (!check_input(count, copy, values)))
	{
		free(copy);
		return (0);
	}
	free(copy);
	return (count - 1);
}
