/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:39:52 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/17 23:14:44 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_top *stack_a, t_top *stack_b, char swap)
{
	if ((swap == 's' || swap == 'a') && stack_a->len > 2)
		logic_swap(stack_a);
	if ((swap == 's' || swap == 'b') && stack_b->len > 2)
		logic_swap(stack_b);
	if (swap == 'a' || swap == 'b' || swap == 's')
		ft_printf("s%c\n", swap);
}

void	push(t_top *stack_a, t_top *stack_b, char swap)
{
	if (swap == 'a' && stack_b->top)
		logic_push(stack_a, stack_b);
	if (swap == 'b' && stack_a->top)
		logic_push(stack_b, stack_a);
	if (swap == 'a' || swap == 'b')
		ft_printf("p%c\n", swap);
}

void	rotate(t_top *stack_a, t_top *stack_b, char swap)
{
	if ((swap == 'a' || swap == 'r') && stack_a->len > 1)
		logic_rotate(stack_a);
	if ((swap == 'b' || swap == 'r') && stack_b->len > 1)
		logic_rotate(stack_b);
	if (swap == 'a' || swap == 'b' || swap == 'r')
		ft_printf("r%c\n", swap);
}

void	rev_rotate(t_top *stack_a, t_top *stack_b, char swap)
{
	if ((swap == 'a' || swap == 'r') && stack_a->len > 1)
		logic_reverse_rotate(stack_a);
	if ((swap == 'b' || swap == 'r') && stack_b->len > 1)
		logic_reverse_rotate(stack_b);
	if (swap == 'a' || swap == 'b' || swap == 'r')
		ft_printf("rr%c\n", swap);
}
