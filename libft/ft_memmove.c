/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:16:11 by jotto             #+#    #+#             */
/*   Updated: 2026/06/13 23:25:41 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;
	size_t				i;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	i = n;
	if (dst_cpy > src_cpy && dst_cpy < src_cpy + n)
	{
		while (i > 0)
		{
			i--;
			dst_cpy[i] = src_cpy[i];
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}

/*intentionally ignoring edgecase: memove(NULL, NULL, 0)
  otherwise inlcude:
	if (n == 0 || dst == src)
        return dst;

int main(void)
{
	char	test[10];
	size_t	i;
	char	letter;

	letter = 65;
	i = 0;
	while (i < 9)
	{
		test[i] = letter;
		i++;
		letter++;
	}

	test[i] = '\0';
	printf("before memove: ");
	printf("%.10s\n", test);
	printf("after memmove: ");
	//ft_memmove(test, test + 2, 3);      // forward overlap
	//ft_memmove(test + 2, test, 5);      // backward overlap
	//ft_memmove(test + 5, test, 2);      // no overlap
	ft_memmove(test, test, 5);          // same source/destination
	printf("%.10s\n", test);
}
*/