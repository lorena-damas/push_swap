/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:49:45 by lordamas          #+#    #+#             */
/*   Updated: 2026/08/09 19:49:45 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != ' ')
			i++;
	}
	return (count);
}

static int	count_all_args(int argc, char **argv)
{
	int	i;
	int	count;
	int	words;

	i = 1;
	count = 1;
	while (i < argc)
	{
		words = count_words(argv[i]);
		if (words == 0)
			return (0);
		count += words;
		i++;
	}
	return (count);
}

static int	add_split(char *arg, char **expanded, int *position)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (split == NULL)
		return (0);
	i = 0;
	while (split[i] != NULL)
	{
		expanded[*position] = split[i];
		(*position)++;
		i++;
	}
	free(split);
	return (1);
}

void	free_expanded_args(t_input *input)
{
	int	i;

	if (input == NULL || input->argv == NULL)
		return ;
	i = 0;
	while (input->argv[i] != NULL)
	{
		free(input->argv[i]);
		i++;
	}
	free(input->argv);
	input->argv = NULL;
}

int	expand_args(int argc, char **argv, t_input *input)
{
	int	i;
	int	position;

	input->argc = count_all_args(argc, argv);
	if (input->argc == 0)
		return (0);
	input->argv = ft_calloc(input->argc + 1, sizeof(char *));
	if (input->argv == NULL)
		return (0);
	input->argv[0] = ft_strdup(argv[0]);
	if (input->argv[0] == NULL)
		return (free_expanded_args(input), 0);
	i = 1;
	position = 1;
	while (i < argc)
	{
		if (!add_split(argv[i], input->argv, &position))
			return (free_expanded_args(input), 0);
		i++;
	}
	return (1);
}
