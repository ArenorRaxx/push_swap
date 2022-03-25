/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protogorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:33:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/23 18:07:54 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	proto_sort(t_top *stack_a, t_top *stack_b)
{
	int	i;

	while (stack_a->top)
		push(stack_a, stack_b, 'b');
	while (stack_b->top)
	{
		i = 0;
		if (!stack_a->top || stack_b->top->val <= stack_a->top->val)
			push(stack_a, stack_b, 'a');
		else
		{
			while (stack_b->top->val > stack_a->top->val)
			{
				if (i == stack_a->len)
					break ;
				rotate(stack_a, stack_b, 'a');
				i++;
			}
			push(stack_a, stack_b, 'a');
			while (i--)
				rev_rotate(stack_a, stack_b, 'a');
		}
	}
}
