/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:32:05 by jotto             #+#    #+#             */
/*   Updated: 2026/06/04 17:52:15 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (const unsigned char *)src;
	while (n > 0)
	{
		*(dst_cp++) = *(src_cp++);
		n--;
	}
	return (dst);
}

/*IMPORTANT NOTE: doesn't handle the case: ft_memcpy(NULL, NULL, 0);
int main(void)
{
	char    *src_str = {"So what is 42?"};
	char    dest1[15];
	char    dest2[10];
	char    dest3[10];

	ft_memcpy(dest1, src_str, 15);
	printf("%s\n", dest1);
	ft_memcpy(dest2, src_str, 7);
	printf("%.8s\n", dest2);
	ft_memcpy(dest3, src_str, 2);
	printf("%s\n", dest3);
}*/