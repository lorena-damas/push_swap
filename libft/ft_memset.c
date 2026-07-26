/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:01:52 by jotto             #+#    #+#             */
/*   Updated: 2026/05/30 17:37:50 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_s;

	temp_s = (unsigned char *) s;
	while (n > 0)
	{
		*(temp_s++) = (unsigned char) c;
		n--;
	}
	return (s);
}

/*This BELOW is all for testing(INCLUDING print_arr FUNC)
void	print_arr(int arr[], int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		printf("%d", arr[i]);
		i++;
	}
}

int	main(void)
{
	char	test_str1[16] = "stringle dingle";
	printf("Test-String before memset: %s\n", test_str1);
	ft_memset(test_str1, '_', 16 * sizeof(char));
	printf("Test-String after memset: %s\n\n", test_str1);

	char	test_str2[16] = "stringle dingle";
	printf("Test-String before memset: %s\n", test_str2);
	ft_memset(test_str2 + 5, '*', 6 * sizeof(char));
	printf("Test-String after memset: %s\n\n", test_str2);

	int	arr_size = 19;
	int test_arr[] = {0,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,0};
	printf("Test-Array before memset:");
	print_arr(test_arr, arr_size);
	printf("\n");
	ft_memset(test_arr, 0, arr_size * sizeof(test_arr[0]));
	printf("Test-Array after memset:");
	print_arr(test_arr, arr_size);
}*/
