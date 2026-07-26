/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:46:47 by jotto             #+#    #+#             */
/*   Updated: 2026/06/03 13:40:29 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	str = ft_calloc(s_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
static char	toupper_wrapper(unsigned int i, char c)
{
	(void)i;
	return ((char)ft_toupper(c));
}

int main(void)
{
	const char	test[] = "hello world!";
	char	*result;
	result = ft_strmapi(test , toupper_wrapper);
	printf("%s\n", result);
	free(result);
}
*/