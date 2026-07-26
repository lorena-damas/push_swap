/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:47:47 by jotto             #+#    #+#             */
/*   Updated: 2026/06/03 14:06:31 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	toupper_wrapper(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = (char)ft_toupper(*c);
}

static void	add_index(unsigned int i, char *c)
{
	*c += i;
}

int main(void)
{
	char	test[] = "hello world!";
	ft_striteri(test , toupper_wrapper);
	printf("After toupper: %s\n", test);
	ft_memset(test, 'a', ft_strlen(test) * sizeof(char));
	printf("After memset: %s\n", test);
	ft_striteri(test, add_index);
	printf("After add_index: %s\n", test);
}
*/