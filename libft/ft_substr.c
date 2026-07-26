/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:54:50 by jotto             #+#    #+#             */
/*   Updated: 2026/06/06 17:34:00 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_cpy;
	size_t	str_len;
	size_t	avail_buf;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	avail_buf = str_len - start;
	if (avail_buf > len)
		avail_buf = len;
	sub_cpy = ft_calloc(avail_buf + 1, sizeof(char));
	if (!sub_cpy)
		return (NULL);
	ft_strlcpy(sub_cpy, (s + start), avail_buf + 1);
	return (sub_cpy);
}
/*
int main(void)
{
	const char str[] = "I am a happy lil string!";
	char	*cpy;
	
	printf("Original String:\n");
	for (int i = 0; str[i]; i++)
	printf("%2d : %c\n", i, str[i]);
	cpy = ft_substr(str, 13,3);
	printf("Substring:\n");
	for (int i = 0; cpy[i]; i++)
	printf("%2d : %c\n", i, cpy[i]);
	free (cpy);
}
*/