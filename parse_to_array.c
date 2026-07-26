#include "push_swap.h"
#include "libft.h"

static int	get_strategy(char *arg, t_strategy *strategy)
{
	if (ft_strncmp(arg, "--simple", 9) == 0 && arg[9] == '\0')
		*strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0 && arg[9] == '\0')
		*strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0 && arg[10] == '\0')
		*strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0 && arg[11] == '\0')
		*strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_args(int argc, char **argv, int *values, t_strategy *strategy)
{
//!!!!!!!!!!!!!!!! UNDER CONSTRUCTION !!!!!!!!!!!!!!!!
}
/*\_*/
