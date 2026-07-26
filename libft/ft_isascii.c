/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:19:36 by jotto             #+#    #+#             */
/*   Updated: 2026/05/18 16:42:08 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	printf("O for no number, 1 for ascii\n");
	printf("expected: 1 return: ");
	printf("%d\n", ft_isascii(77));

	printf("expected: 1 return: ");
	printf("%d\n", ft_isascii(0));

	printf("expected: 1 return: ");
	printf("%d\n", ft_isascii(127));

	printf("expected: 0 return: ");
	printf("%d\n", ft_isascii(128));

	printf("expected: 1 return: ");
	printf("%d\n", ft_isascii(25));
}
*/