/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_helper_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:12:38 by jotto             #+#    #+#             */
/*   Updated: 2026/07/30 14:22:58 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

//just a copy of c0mpute_disorder for testing purpose
double compute_disorder(int *a, int count)
{
    int mistakes;
    int total;
    int i;
    int j;
    double disorder;

    mistakes = 0;
    total = 0;
    i = 0;
    while (i < count)
    {
        j = i + 1;
        while (j < count)
        {
            if (a[i] > a[j])
                mistakes++;
            total++;
            j++;
        }
        i++;
    }
    if (total == 0)
        return (0.0);
    disorder = (double)mistakes / (double)total;
    return (disorder);
}

static void	print_strategy(t_strategy strat)
{
	if (strat == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (strat == MEDIUM)
		ft_putstr_fd("Medium / O(n log n)\n", 2);
	else if (strat == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n\u221An)\n", 2);
}

//completly kaputt :( (and frac section needs to be put in a seperate function)
void	bench_print(double disorder, t_strategy strat)
{
	int	percent;
	int whole;
	int frac;
	t_bench *t_bench;

	t_bench = bench_get_t_bench();
	percent = //?????;
	whole =	percent / 100;//???
	frac =	percent % 100;//???
	ft_putstr_fd("[bench] disorder:\t", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (frac < 10)
	{
		ft_putstr_fd("0", 2);
		ft_putnbr_fd(frac, 2);
	}
	else
		ft_putnbr_fd(frac, 2);
	//percentage doenst show up as exspected
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy:\t", 2);
	print_strategy(strat);
	ft_putstr_fd("[bench] total_ops:\t", 2);
	ft_putnbr_fd(t_bench.total_ops, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa:\t", 2);
	ft_putnbr_fd(t_bench.sa, 2);
	ft_putstr_fd("\tsb:\t", 2);
	ft_putnbr_fd(t_bench.sb, 2);
	ft_putstr_fd("\tss:\t", 2);
	ft_putnbr_fd(t_bench.ss, 2);
	ft_putstr_fd("\tpa:\t", 2);
	ft_putnbr_fd(t_bench.pa, 2);
	ft_putstr_fd("\tpb:\t", 2);
	ft_putnbr_fd(t_bench.pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra:\t", 2);
	ft_putnbr_fd(t_bench.ra, 2);
	ft_putstr_fd("\trb:\t", 2);
	ft_putnbr_fd(t_bench.rb, 2);
	ft_putstr_fd("\trr:\t", 2);
	ft_putnbr_fd(t_bench.rr, 2);
	ft_putstr_fd("\trra:\t", 2);
	ft_putnbr_fd(t_bench.rra, 2);
	ft_putstr_fd("\trrb:\t", 2);
	ft_putnbr_fd(t_bench.rrb, 2);
	ft_putstr_fd("\trrr:\t", 2);
	ft_putnbr_fd(t_bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

//i think this approach is completly idiotic, i dont know what i was thinking
int bench_extract_args(int argc, char **argv, int *values, t_strategy *strat)
{
	char	**argv2;
	int		i;
	int		j;
	int		sizea;

	argv2 = malloc(sizeof(*argv2) * (size_t)argc);
	if (argv2 == NULL)
		return (-1);
	argv2[0] = argv[0];
	i = 1;
	j = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) != 0)
		{
			argv2[j] = argv[i];
			j++;
		}
		i++;
	}
	sizea = parse_args(j, argv2, values, strat);
	free(argv2);
	return (sizea);
}
