/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:32:29 by jotto             #+#    #+#             */
/*   Updated: 2026/06/14 12:52:47 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c);

static void		free_arr(char **arr, size_t i);

static size_t	word_len(const char *str, char c, size_t *start);

static char		**put_wrd(char **str_arr, const char *str, char c);

char			**ft_split(char const *s, char c);

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count += 1;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_arr(char **arr, size_t i)
{
	while (i > 0)
		free (arr[--i]);
	free (arr);
}

static size_t	word_len(const char *str, char c, size_t *start)
{
	size_t	len;

	while (str[*start] && str[*start] == c)
		(*start)++;
	len = 0;
	while (str[*start + len] && str[*start + len] != c)
		len++;
	return (len);
}

static char	**put_wrd(char **str_arr, const char *str, char c)
{
	size_t	element;
	size_t	len;
	size_t	i;
	size_t	start;

	element = 0;
	i = 0;
	while (str[i])
	{
		start = i;
		len = word_len(str, c, &start);
		i = start + len;
		if (len > 0)
		{
			str_arr[element] = ft_substr(str, start, len);
			if (!str_arr[element])
			{
				free_arr(str_arr, element);
				return (NULL);
			}
			element++;
		}
	}
	str_arr[element] = NULL;
	return (str_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	arr_size;

	if (!s)
		return (NULL);
	arr_size = word_count(s, c);
	str_arr = malloc((arr_size + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	return (put_wrd(str_arr, s, c));
}
/*
int	main(void)
{
	size_t		i;
	char		**str_arr;
	const char	test[] = "    hello world ban p  labub han,crow 42 strawby";

	i = word_count(test, ' ');
	printf("Wordcounter: %zu\n", i);
	str_arr = ft_split(test, ' ');
	if (!str_arr)
		return (1);
	i = 0;
	while (str_arr[i])
	{
		printf("[%zu]%s\n", i + 1, str_arr[i]);
		i++;
	}
}*/
