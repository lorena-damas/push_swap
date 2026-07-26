/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:17:47 by jotto             #+#    #+#             */
/*   Updated: 2026/06/12 00:54:22 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*tmp_s;

	tmp_s = s;
	i = 0;
	while (tmp_s[i])
	{
		if (tmp_s[i] == (char)c)
			return ((char *)(tmp_s + i));
		i++;
	}
	if (tmp_s[i] == (char)c)
		return ((char *)(tmp_s + i));
	return (NULL);
}

/* int main(void)
{
	char test_str[] = {"Beginning.......X.......X......X......X....End"};
	printf("%s\n", ft_strchr(test_str, 'X'));
}*/