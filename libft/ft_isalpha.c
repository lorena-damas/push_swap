/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:45:22 by jotto             #+#    #+#             */
/*   Updated: 2026/05/18 16:42:13 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	printf("O for no number, 1 for alpha-numericals\n");
	printf("expected: 1 return: ");
	printf("%d\n",ft_isalpha(77));

	printf("expected: 1 return: ");
	printf("%d\n",ft_isalpha(97));

	printf("expected: 0 return: ");
	printf("%d\n",ft_isalpha(38));

	printf("expected: 1 return: ");
	printf("%d\n",ft_isalpha(65));

	printf("expected: 0 return: ");
	printf("%d\n",ft_isalpha(123));

	printf("expected: 0 return: ");
	printf("%d\n",ft_isalpha(0));
}*/