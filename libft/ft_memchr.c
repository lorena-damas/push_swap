/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:19:43 by jotto             #+#    #+#             */
/*   Updated: 2026/06/01 19:53:52 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
			return (tmp_s + i);
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
	unsigned char *dest1;
	unsigned char *dest2;
	unsigned char *dest3;
	const char test[] = ".-.-.-.-.-.-.A.-.-.-.-.-";
	
	dest1 = ft_memchr(test, 'A', 13);
	dest2 = ft_memchr(test, 'A', 14);
	dest3 = ft_memchr(test, 'A', 24);
	printf("%s\n%s\n%s\n", dest1, dest2, dest3);
}*/