/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:27:28 by jotto             #+#    #+#             */
/*   Updated: 2026/06/11 18:52:28 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf("O for no number, 1 for printable char\n");
	printf("expected: 1 return: ");
	printf("%d\n", ft_isprint(77));
	
	printf("expected: 1 return: ");
	printf("%d\n", ft_isprint(127));

	printf("expected: 1 return: ");
	printf("%d\n", ft_isprint(32));

	printf("expected: 0 return: ");
	printf("%d\n", ft_isprint(0));

	printf("expected: 0 return: ");
	printf("%d\n", ft_isprint(31));

}*/