/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 09:54:56 by jotto             #+#    #+#             */
/*   Updated: 2026/06/13 21:24:44 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("one");
	ft_lstadd_back(&lst, ft_lstnew("two"));
	ft_lstadd_back(&lst, ft_lstnew("three"));
	printf("%s -> %s -> %s\n",
		(char *)lst->content,
		(char *)lst->next->content,
		(char *)lst->next->next->content);
	ft_lstclear(&lst, NULL);
	return (0);
}*/