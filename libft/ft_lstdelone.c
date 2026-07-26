/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:30:30 by jotto             #+#    #+#             */
/*   Updated: 2026/06/13 22:20:51 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

/*
typedef struct s_test
{
	char	*name;
	int		nmb;
}	t_test;

void	del_string(void *content)
{
	free(content);
}

void	del_nothing(void *content)
{
	(void)content;
}

void	del_test(void *content)
{
	t_test	*p;

	p = (t_test *)content;
	free(p->name);
	free(p);
}


int	main(void)
{
	t_list		*node;
	char		*str;
	int			x;
	t_test		*test;

	//simple string
	str = strdup("42");
	node = ft_lstnew(str);
	ft_lstdelone(node, del_string);

	//normal varable on stack
	x = 42;
	node = ft_lstnew(&x);
	ft_lstdelone(node, del_nothing);

	//struct
	test = malloc(sizeof(t_test));
	test->name = strdup("labubu");
	test->nmb = 43;
	node = ft_lstnew(test);
	ft_lstdelone(node, del_test);

	return (0);
}*/