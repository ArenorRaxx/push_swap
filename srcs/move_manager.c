/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:39:52 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/05 17:07:31 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_top *stack_a, t_top *stack_b, char swap, int pseudo)
{
	int	print;

	print = 0;
	if ((swap == 's' || swap == 'a') && stack_a->len >= 2)
	{
		logic_swap(stack_a);
		print = 1;
	}
	if ((swap == 's' || swap == 'b') && stack_b->len >= 2)
	{
		logic_swap(stack_b);
		print = 1;
	}
	if (print && !pseudo)
		ft_printf("s%c\n", swap);
}

void	push(t_top *stack_a, t_top *stack_b, char swap, int pseudo)
{
	int	print;

	print = 0;
	if (swap == 'a' && stack_b->top)
	{
		logic_push(stack_a, stack_b);
		print = 1;
	}
	else if (swap == 'b' && stack_a->top)
	{
		logic_push(stack_b, stack_a);
		print = 1;
	}
	else
		write(1, "Nique !\n", 8);
	if (print && !pseudo)
		ft_printf("p%c\n", swap);
}

void	rotate(t_top *stack_a, t_top *stack_b, char swap, int pseudo)
{
	int	print;

	print = 0;
	if ((swap == 'a' || swap == 'r') && stack_a->len > 1)
	{
		logic_rotate(stack_a);
		print = 1;
	}
	if ((swap == 'b' || swap == 'r') && stack_b->len > 1)
	{
		logic_rotate(stack_b);
		print = 1;
	}
	if (print && !pseudo)
		ft_printf("r%c\n", swap);
}

void	rev_rotate(t_top *stack_a, t_top *stack_b, char swap, int pseudo)
{
	int	print;

	print = 0;
	if ((swap == 'a' || swap == 'r') && stack_a->len > 1)
	{
		logic_reverse_rotate(stack_a);
		print = 1;
	}
	if ((swap == 'b' || swap == 'r') && stack_b->len > 1)
	{
		logic_reverse_rotate(stack_b);
		print = 1;
	}
	if (print && !pseudo)
		ft_printf("rr%c\n", swap);
}
