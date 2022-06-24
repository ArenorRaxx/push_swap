/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:24:20 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/24 17:59:22 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_top stack_a)
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

static void	sort_list(int **list, int len)
{
	int	i;
	int	j;
	int	h;

	i = 0;
	h = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if ((*list)[j] > (*list)[j + 1])
			{
				h = (*list)[j];
				(*list)[j] = (*list)[j + 1];
				(*list)[j + 1] = h;
			}
			j++;
		}
		i++;
	}
}

static int	convert_stack(t_top *stack_a)
{
	int		i;
	int		*val_tab;
	t_node	*curr_node;

	i = 0;
	val_tab = malloc(sizeof(*val_tab) * stack_len(*stack_a));
	if (!val_tab)
		return (-1);
	curr_node = stack_a->top;
	while (curr_node)
	{
		val_tab[i++] = curr_node->val;
		curr_node = curr_node->next;
	}
	sort_list(&val_tab, stack_len(*stack_a));
	curr_node = stack_a->top;
	while (curr_node)
	{
		i = -1;
		while (++i < stack_len(*stack_a))
			if (val_tab[i] == curr_node->val)
				curr_node->val = i;
		curr_node = curr_node->next;
	}
	free(val_tab);
	return (0);
}

static void	radix_sort(t_top *stack_a, t_top *stack_b)
{
	int	i;
	int	j;
	int	nb_bits;
	int	high_num;

	i = 0;
	nb_bits = 0;
	high_num = stack_len(*stack_a) - 1;
	while ((high_num >> nb_bits) != 0)
		nb_bits++;
	while (i < nb_bits)
	{
		j = 0;
		while (j <= high_num)
		{
			if ((stack_a->top->val >> i) & 1)
				rotate(stack_a, stack_b, 'a', 0);
			else
				push(stack_a, stack_b, 'b', 0);
			j++;
		}
		while (stack_b->top)
			push(stack_a, stack_b, 'a', 0);
		i++;
	}
}

int	resolver(t_top *stack_a, int argc)
{
	t_top	stack_b;

	stack_b.len = 0;
	stack_b.top = NULL;
	stack_b.bottom = NULL;
	if (argc <= 2)
		return (0);
	if (argc == 2)
		if (stack_a->top->val < stack_a->top->next->val)
			swap(stack_a, &stack_b, 'a', 0);
	if (argc > 2)
	{
		convert_stack(stack_a);
		if (is_sorted(*stack_a) == 0)
			return (0);
		else if (argc <= 7)
			return (brute_force(stack_a, &stack_b));
		else
			radix_sort(stack_a, &stack_b);
	}	
	return (0);
}
