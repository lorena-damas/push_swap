/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:19:14 by jotto             #+#    #+#             */
/*   Updated: 2026/06/13 21:44:30 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*tmp_s;

	tmp_s = s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (tmp_s[i] == (char)c)
			return ((char *)(tmp_s + i));
		i--;
	}
	return (NULL);
}

/*int main(void)
{
	char test_str[] = {"Beginning.......X.......X......X......X....End"};
	printf("%s\n", ft_strrchr(test_str, 'X'));
}*/