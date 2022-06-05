/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:24:20 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/05 17:48:55 by mcorso           ###   ########.fr       */
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

static int	brute_force(t_top *stack_a)
{
	int			set_len;
	t_top		stack_b;
	static int	*set;

	set_len = 0;
	stack_b.len = 0;
	stack_b.top = NULL;
	stack_b.bottom = NULL;
	while (is_sorted(*stack_a) < 0)
	{
		if (set)
			if (rev_pseudo_exec(set, set_len, stack_a, &stack_b) < 0)
				return (-1);
		while (1)
		{
			set_len = next_set(&set);
			if (set_len < 0)
				return (-1);
			if (check_set(set) < 0)
				continue ;
			break ;
		}
		pseudo_exec(set, stack_a, &stack_b, 1);
	}
	pseudo_exec(set, stack_a, &stack_b, 0);
	return (0);
}

int	resolver(t_top *stack_a, int argc)
{
	t_top	stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		if (stack_a->top->val < stack_a->top->next->val)
			swap(stack_a, &stack_b, 'a', 0);
	if (argc > 2)
	{
		if (is_sorted(*stack_a) == 0)
			return (0);
		else
			brute_force(stack_a);
	}
	return (0);
}
