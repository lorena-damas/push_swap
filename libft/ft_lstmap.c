/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:28:47 by jotto             #+#    #+#             */
/*   Updated: 2026/06/13 21:25:02 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (del)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
void	*to_upper(void *content)
{
	char	*s;
	int		i;

	s = strdup((char *)content);
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_lst;

	lst = ft_lstnew(strdup("one"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("two")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("three")));
	new_lst = ft_lstmap(lst, to_upper, del);
	printf("%s -> %s -> %s\n",
		(char *)new_lst->content,
		(char *)new_lst->next->content,
		(char *)new_lst->next->next->content);
	ft_lstclear(&lst, del);
	ft_lstclear(&new_lst, del);
	return (0);
}*/