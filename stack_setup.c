/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lordamas <lordamas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:22:47 by lordamas          #+#    #+#             */
/*   Updated: 2026/07/18 19:00:13 by lordamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

int	add_node_back(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(value);
	if (new_node == NULL)
		return (0);
	if (stack->top == NULL)
	{
		/* O que deve acontecer aqui? */
	}
	else
	{
		current = stack->top;
		/* Depois percorreremos até o último nó */
	}
	return (1);
}
