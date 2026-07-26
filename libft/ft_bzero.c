/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:28:45 by jotto             #+#    #+#             */
/*   Updated: 2026/05/30 20:02:17 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int main(void)
{
    char test_str[] = "Hello, World!";
    printf("Before ft_bzero: %s\n", test_str);
    ft_bzero(test_str, sizeof(test_str));
    printf("After ft_bzero: %s\n", test_str);
    return 0;  
}*/