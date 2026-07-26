/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 18:21:01 by jotto             #+#    #+#             */
/*   Updated: 2026/06/14 12:02:33 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	total_bufsize;

	if (size != 0 && n > ((size_t)-1 / size))
		return (NULL);
	total_bufsize = n * size;
	ptr = malloc(total_bufsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_bufsize);
	return (ptr);
}

/*
int main(void)
{
	char	*buffer_ptr;
	void	*p;

	size_t	nmb_of_bufelements;
	size_t	i;

	nmb_of_bufelements = 20;
	buffer_ptr = ft_calloc(nmb_of_bufelements, sizeof(char));
	if (!buffer_ptr)
		return (1);
	printf("%s\n", buffer_ptr);    //should print empty line
	i = 0;
	while (i < nmb_of_bufelements)
	{
		printf("%d ", buffer_ptr[i]);	//should print zeroes
		i++;
	}
	printf("\n");
	p = ft_calloc(0, 10);	//testing if return-value is valid pointer
	printf("%p\n", p);
	free(p);

	p = ft_calloc(10, 0);
	printf("%p\n", p);
	free(p);
	free (buffer_ptr);
}
*/