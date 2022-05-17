/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:24:20 by mcorso            #+#    #+#             */
/*   Updated: 2022/04/26 20:34:59 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sorted(t_top stack_a)
{
	t_node	*curr_node;

	curr_node = stack_a.top;
	while (curr_node->val <= curr_node->next->val)
	{
		curr_node = curr_node->next;
		if (!curr_node->next)
			return (0);
	}
	return (-1);
}

static void	sort_three(t_top *stack_a)
{
	if (stack_a->top->val > stack_a->top->next->val)
	{
		if (stack_a->top->next->val < stack_a->bottom->val)
		{
			if (stack_a->top->val > stack_a->bottom->val)
				rotate(stack_a, NULL, 'a', 0);
			else
				swap(stack_a, NULL, 'a', 0);
		}
		else
		{
			swap(stack_a, NULL, 'a', 0);
			rev_rotate(stack_a, NULL, 'a', 0);
		}
	}
	else
	{
		if (stack_a->top->val > stack_a->bottom->val)
			rev_rotate(stack_a, NULL, 'a', 0);
		else
		{
			swap(stack_a, NULL, 'a', 0);
			rotate(stack_a, NULL, 'a', 0);
		}
	}
}

static int	brute_force(t_top *stack_a)
{
	char	*set;

	set = NULL;
	while (is_sorted(*stack_a) < 0)
	{
		if (set)
			rev_pseudo_exec(set, *stack_a);
		next_set(&set);
		pseudo_exec(set, *stack_a);
	}
	display_stack(*stack_a, 'A');
	//exec(set);
	return (0);
}

int	resolver(t_top *stack_a, int argc)
{
	t_top	stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		if (stack_a->top->val < stack_a->top->next->val)
			swap(stack_a, &stack_b, 'a');
	if (argc > 2)
	{
		if (is_sorted(*stack_a) == 0)
			return (0);
		else if (argc == 4)
			sort_three(stack_a);
		else
			brute_force(stack_a);
	}
	return (0);
}
