/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:14:44 by jotto             #+#    #+#             */
/*   Updated: 2026/05/18 16:54:59 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	printf("O for no number, 1 for number\n");
	printf("expected: 1 return: ");
	printf("%d\n",ft_isalnum(50));
	printf("expected: 1 return: ");
	printf("%d\n",ft_isalnum(57));
	printf("expected: 0 return: ");
	printf("%d\n",ft_isalnum(58));
	printf("expected: 1 return: ");
	printf("%d\n",ft_isalnum(65));
	printf("expected: 1 return: ");
	printf("%d\n",ft_isalnum(77));
	printf("expected: 0 return: ");
	printf("%d\n",ft_isalnum(0));
}*/