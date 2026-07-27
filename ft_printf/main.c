/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:33:46 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/09 13:34:22 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	print_separator(char *title)
{
	printf("\n");
	printf("========================================\n");
	printf("  %s\n", title);
	printf("========================================\n");
}

static void	print_result(int ret1, int ret2)
{
	printf("\n");
	printf("printf return    : %d\n", ret1);
	printf("ft_printf return : %d\n", ret2);
	if (ret1 == ret2)
		printf("STATUS           : OK\n");
	else
		printf("STATUS           : KO\n");
}

int	main(void)
{
	int		ret1;
	int		ret2;
	int		n;
	char	*str;
	char	*null_str;
	void	*null_ptr;

	setbuf(stdout, NULL);
	n = 42;
	str = "Ana";
	null_str = NULL;
	null_ptr = NULL;

	print_separator("TEXT ONLY");
	printf("printf    : [");
	ret1 = printf("Hello 42");
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("Hello 42");
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("PERCENT %%");
	printf("printf    : [");
	ret1 = printf("Progress: 100%%");
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("Progress: 100%%");
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("CHAR %%c");
	printf("printf    : [");
	ret1 = printf("Char: %c", 'A');
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("Char: %c", 'A');
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("CHAR NULL %%c");
	printf("printf    : [");
	ret1 = printf("Before%cAfter", '\0');
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("Before%cAfter", '\0');
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("STRING %%s");
	printf("printf    : [");
	ret1 = printf("Name: %s", str);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("Name: %s", str);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("STRING NULL %%s");
	printf("printf    : [");
	ret1 = printf("Name: %s", null_str);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("Name: %s", null_str);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("DECIMAL %%d");
	printf("printf    : [");
	ret1 = printf("%d | %d | %d", 0, 42, INT_MIN);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("%d | %d | %d", 0, 42, INT_MIN);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("INTEGER %%i");
	printf("printf    : [");
	ret1 = printf("%i | %i | %i", 0, -42, INT_MAX);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("%i | %i | %i", 0, -42, INT_MAX);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("UNSIGNED %%u");
	printf("printf    : [");
	ret1 = printf("%u | %u | %u", 0u, 42u, UINT_MAX);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("%u | %u | %u", 0u, 42u, UINT_MAX);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("HEXADECIMAL LOWER %%x");
	printf("printf    : [");
	ret1 = printf("%x | %x | %x", 0u, 255u, UINT_MAX);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("%x | %x | %x", 0u, 255u, UINT_MAX);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("HEXADECIMAL UPPER %%X");
	printf("printf    : [");
	ret1 = printf("%X | %X | %X", 0u, 255u, UINT_MAX);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("%X | %X | %X", 0u, 255u, UINT_MAX);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("POINTER %%p");
	printf("printf    : [");
	ret1 = printf("ptr: %p", &n);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("ptr: %p", &n);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("POINTER NULL %%p");
	printf("printf    : [");
	ret1 = printf("ptr: %p", null_ptr);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("ptr: %p", null_ptr);
	printf("]\n");
	print_result(ret1, ret2);

	print_separator("MIXED TEST");
	printf("printf    : [");
	ret1 = printf("c:%c s:%s p:%p d:%d i:%i u:%u x:%x X:%X %%",
			'Z', "test", &n, -42, 42, 42u, 255u, 255u);
	printf("]\n");
	printf("ft_printf : [");
	ret2 = ft_printf("c:%c s:%s p:%p d:%d i:%i u:%u x:%x X:%X %%",
			'Z', "test", &n, -42, 42, 42u, 255u, 255u);
	printf("]\n");
	print_result(ret1, ret2);

	printf("\n");
	printf("========================================\n");
	printf("  TESTS FINISHED\n");
	printf("========================================\n");
	return (0);
}
