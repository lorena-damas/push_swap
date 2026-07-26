/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:07:12 by jotto             #+#    #+#             */
/*   Updated: 2026/06/06 18:06:34 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*int	main(int argc, char **argv)
{
	if (argc > 2 || argc < 2)
		return (0);
	printf("Len of string \"%s\" is %zu\n", argv[1], ft_strlen(argv[1]));
}*/