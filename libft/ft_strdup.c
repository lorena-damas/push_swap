/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:21:24 by jotto             #+#    #+#             */
/*   Updated: 2026/06/06 19:11:42 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
int main(void)
{
	const char	test_str[] = "Hacking the Mainframe...";
	char	*test_cpy;
	char	*test_cpy2;

	test_cpy = ft_strdup(test_str);
	printf("%s\n", test_cpy);
	free(test_cpy);
	test_cpy2 = ft_strdup("");
	printf("'%s'\n", test_cpy2);
	free(test_cpy2);
}
*/