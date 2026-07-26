/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:53:36 by jotto             #+#    #+#             */
/*   Updated: 2026/05/18 17:49:14 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*int	main(void)
{
	char dest_TEST1[10];
	char dest_TEST2[7];
	char dest_TEST3[5];

	printf("TEST 1: returned length is %zu\n",
	ft_strlcpy(dest_TEST1, "labubu", 10));
	printf("destination-string: %s\n\n", dest_TEST1);

	printf("TEST 2: returned length is %zu\n",
	ft_strlcpy(dest_TEST2, "labubu", 6));
	printf("destination-string: %s\n\n", dest_TEST2);
	
	printf("TEST 3: returned length is %zu\n",
	ft_strlcpy(dest_TEST3, "labubu", 5));
	printf("destination-string: %s\n", dest_TEST3);
}*/