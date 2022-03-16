/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:24:24 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/16 15:14:13 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	init_stack(t_top *stack)
{
	t_node	*first_node;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (-1);
	first_node = malloc(sizeof(*first_node));
	if (!first_node)
		return (-1);
	first_node->val = 0;
	first_node->prev = NULL;
	first_node->next = NULL;
	stack->top = first_node;
	stack->bottom = first_node;
	return (0);
}

int	add_on_stack(t_top *stack, int val)
{
	t_node	*top_node;
	t_node	*new_node;

	top_node = stack->top;
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (-1);
	new_node->val = val;
	new_node->prev = NULL;
	new_node->next = top_node;
	top_node->prev = new_node;
	stack->top = new_node;
	return (0);
}

// If mode, go to top. Else, go to bottom.
t_node	*top_or_bottom(t_node node, int mode)
{
	t_node	*curr_node;

	curr_node = &node;
	if (mode)
		while (curr_node->next)
			curr_node = curr_node->next;
	else
		while (curr_node->prev)
			curr_node = curr_node->prev;
	return (curr_node);
}

int	free_stack(t_top top_node)
{
	t_node	*next_node;
	t_node	*curr_node;

	curr_node = top_node.top;
	while (curr_node)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	return (0);
}
