/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:24:24 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/27 15:11:26 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	add_on_stack(t_top *stack, int val)
{
	t_node	*new_node;
	t_node	*bot_node;

	bot_node = stack->bottom;
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (-1);
	new_node->val = val;
	new_node->next = NULL;
	new_node->prev = bot_node;
	bot_node->next = new_node;
	stack->bottom = new_node;
	return (0);
}

int	stack_len(t_top stack)
{
	int		len;
	t_node	*curr_node;

	len = 0;
	curr_node = stack.top;
	while (curr_node)
	{
		curr_node = curr_node->next;
		len++;
	}
	return (len);
}

int	init_stack(t_top *stack)
{
	t_node	*first_node;

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

int	free_stack(t_top *stack)
{
	t_node	*next_node;
	t_node	*curr_node;

	curr_node = stack->top;
	while (curr_node)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	return (0);
}

int	fill_stack(t_top *stack_a, char **form_args)
{
	int		i;
	int		val;

	i = 0;
	while (form_args[i])
	{
		val = ft_atoi(form_args[i]);
		if (!i)
			stack_a->top->val = val;
		else if (add_on_stack(stack_a, val) < 0)
			return (-1);
		i++;
	}
	stack_a->len = stack_len(*stack_a);
	return (0);
}
