/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:08:35 by jotto             #+#    #+#             */
/*   Updated: 2026/05/18 15:22:38 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf("O for no number, 1 for digit\n");
	printf("expected: 0 return: ");
	printf("%d\n", ft_isdigit(77));

	printf("expected: 0 return: ");
	printf("%d\n", ft_isdigit(0));

	printf("expected: 1 return: ");
	printf("%d\n", ft_isdigit(48));

	printf("expected: 1 return: ");
	printf("%d\n", ft_isdigit(57));

	printf("expected: 0 return: ");
	printf("%d\n", ft_isdigit(47));

}*/