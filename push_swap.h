/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:31:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/16 15:09:54 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*/		STACK MANAGEMENT	/*/
typedef struct s_node {
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_top {
	t_node	*top;
	t_node	*bottom;
}				t_top;

static inline void	swap(t_top *stack_one, t_top *stack_two)
{
	t_node	*tmp;
	t_node	*top_node_one;
	t_node	*top_node_two;

	top_node_one = stack_one->top;
	top_node_two = stack_two->top;
	stack_one->top = top_node_two;
	stack_two->top = top_node_one;
	tmp = top_node_two->next;
	top_node_one->next = top_node_two->next;
	top_node_two->next = tmp;
	top_node_one->next->prev = top_node_one;
	top_node_two->next->prev = top_node_two;
}

static inline void	push(t_top *stack_one, t_top *stack_two)
{
	t_node	*top_node_one;
	t_node	*top_node_two;

	top_node_one = stack_one->top;
	top_node_two = stack_two->top;
	stack_one->top = top_node_two;
	stack_two->top = top_node_two->next;
	top_node_two->prev = NULL;
	top_node_one->prev = top_node_two;
	top_node_two->next = top_node_one;
}

static inline void	rotate(t_top *stack)
{
	t_node	*top_node;
	t_node	*bot_node;

	top_node = stack->top;
	bot_node = stack->bottom;
	stack->bottom = top_node;
	stack->top = top_node->next;
	bot_node->next = top_node;
	top_node->prev = bot_node;
	top_node->next = NULL;
}

static inline void	reverse_rotate(t_top *stack)
{
	t_node	*top_node;
	t_node	*bot_node;

	top_node = stack->top;
	bot_node = stack->bottom;
	stack->top = bot_node;
	stack->bottom = bot_node->prev;
	bot_node->prev = NULL;
	bot_node->next = top_node;
	top_node->prev = bot_node;
}

#endif