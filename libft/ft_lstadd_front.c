/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotto <jotto@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:57:52 by jotto             #+#    #+#             */
/*   Updated: 2026/06/12 01:38:43 by jotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew("one");
	new = ft_lstnew("two");
	ft_lstadd_front(&lst, new);
	printf("%s......%s\n", (char *)lst->content, (char *)lst->next->content);
	ft_lstclear(&lst, NULL);
	return (0);
}*/