/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:24:24 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/16 13:43:38 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	init_stack(t_parent	*parent_node)
{
	t_node	*first_node;

	parent_node = malloc(sizeof(*parent_node));
	if (!parent_node)
		return (-1);
	first_node = malloc(sizeof(*first_node));
	if (!first_node)
		return (-1);
	first_node->val = 0;
	first_node->prev = NULL;
	first_node->next = NULL;
	parent_node->first_node = first_node;
	return (0);
}

int	add_node(t_node *previous_node, int val)
{
	t_node	*next_node;

	next_node = malloc(sizeof(*next_node));
	if (!next_node)
		return (-1);
	previous_node->next = next_node;
	next_node->prev = previous_node;
	next_node->next = NULL;
	next_node->val = val;
	return (0);
}

// If mode, go to first. Else, go to last.
t_node	*multi_go_to(t_node *node, int mode)
{
	t_node	*curr_node;

	curr_node = node;
	if (mode)
		while (curr_node->prev)
			curr_node = curr_node->prev;
	else
		while (curr_node->next)
			curr_node = curr_node->next;
	return (curr_node);
}

int	free_stack(t_parent parent_node)
{
	t_node	*next_node;
	t_node	*curr_node;

	curr_node = parent_node.first_node;
	while (curr_node)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	return (0);
}
