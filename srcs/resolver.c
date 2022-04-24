/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:24:20 by mcorso            #+#    #+#             */
/*   Updated: 2022/04/24 16:01:31 by mcorso           ###   ########.fr       */
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
				rotate(stack_a, NULL, 'a');
			else
				swap(stack_a, NULL, 'a');
		}
		else
		{
			swap(stack_a, NULL, 'a');
			rev_rotate(stack_a, NULL, 'a');
		}
	}
	else
	{
		if (stack_a->top->val > stack_a->bottom->val)
			rev_rotate(stack_a, NULL, 'a');
		else
		{
			swap(stack_a, NULL, 'a');
			rotate(stack_a, NULL, 'a');
		}
	}
}

int	brute_force(char **formated_args, t_top *stack_a, t_top *stack_b)
{
	char	*set;
	t_top	tmp_a;

	set = NULL;
	if (init_stack(&tmp_a) < 0)
		return (-1);
	if (fill_stack(&tmp_a, formated_args) < 0)
		return (-1);
	while (is_sorted(tmp_a) < 0)
	{
		rev_pseudo_exec(set, tmp_a);
		next_set(&set);
		pseudo_exec(set, tmp_a);
	}
	exec(instruct, stack_a, stack_b);
	return (0);
}

int	resolver(t_top *stack_a, t_top *stack_b, int argc)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
		if (stack_a->top->val < stack_a->top->next->val)
			swap(stack_a, stack_b, 'a');
	if (argc > 2)
	{
		if (is_sorted(*stack_a) == 0)
			return (0);
		else if (argc == 4)
			sort_three(stack_a);
	}
	return (0);
}
