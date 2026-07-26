/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:20:06 by jotto             #+#    #+#             */
/*   Updated: 2026/06/01 20:42:04 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cast_s1;
	const unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && cast_s1[i] == cast_s2[i])
		i++;
	if (i == n)
		return (0);
	return (cast_s1[i] - cast_s2[i]);
}

/*int main(void)
{
	const char str1[] = "ABCDEfg";
	const char str2[] = "ABCDEFG";
	
	printf("%d\n", ft_memcmp(str1, str2, 5));
	printf("%d\n", ft_memcmp(str1, str2, 6));
	printf("%d\n", ft_memcmp(str1, str2, 0));
	printf("%d\n", ft_memcmp(str2, str1, ft_strlen(str1)));
}*/