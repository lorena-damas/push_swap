/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 21:32:59 by jotto             #+#    #+#             */
/*   Updated: 2026/07/27 01:42:03 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

int	parse_args(int argc, char **argv, int *values, t_strategy *strategy)
{
//!!!!!!!!!!!!!!!! UNDER CONSTRUCTION --------- LONGER THAN 25 LINES !!!!!!!!!!!!!!!!

	char	**copy;
	int		count;
	int		i;
	int		returnvalue;

	*strategy = ADAPTIVE;
	copy = malloc(argc * sizeof(*copy));
	if (copy == NULL)
		return (0);
	copy[0] = argv[0];
	count = 1;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!get_strategy(argv[i], strategy))
			{
				free(copy);
				return (0);
			}
		}
		else
		{
			copy[count++] = argv[i];
		}
		i++;
	}
	if (count == 1)
	{
		free(copy);
		return (0);
	}
	returnvalue = check_input(count, copy, values);
	free(copy);
	return (returnvalue);
}
/*\_*/
