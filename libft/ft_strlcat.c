/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:58:05 by jotto             #+#    #+#             */
/*   Updated: 2026/05/31 21:20:58 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*int	main(void)
{
	char dest_TEST1[99] = "start@and@";
	char dest_TEST2[99] = "start@and@";
	char dest_TEST3[12] = "start@and@";
	char dest_TEST4[99] = "start@and@";

	size_t	return_len;

	return_len = ft_strlcat(dest_TEST1, "finish", 99);
	printf("TEST 1: return len: %zu\n", return_len);
	printf("dest string: %s\n\n", dest_TEST1);

	return_len = ft_strlcat(dest_TEST2, "finish", 0);
	printf("TEST 2: return len: %zu\n", return_len);
	printf("dest string: %s\n\n", dest_TEST2);

	return_len = ft_strlcat(dest_TEST3, "finish", 14);
	printf("TEST 3: return len: %zu\n", return_len);
	printf("dest string: %s\n\n", dest_TEST3);

	return_len = ft_strlcat(dest_TEST4, "", 99);
	printf("TEST 4: return len: %zu\n", return_len);
	printf("dest string: %s\n\n", dest_TEST4);

}*/