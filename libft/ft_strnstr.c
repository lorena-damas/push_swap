/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:20:36 by jotto             #+#    #+#             */
/*   Updated: 2026/06/13 21:54:06 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] && i + j < n
			&& haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	haystack[] = "hayhayhayhayhayhayhayhayhayhayNEEDLEhayhayhay";
	printf("Haystack: %s\nFound substring: %s\n", haystack,
		 ft_strnstr(haystack, "NEEDLE", 40));
}*/