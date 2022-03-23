/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:31:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/23 10:32:24 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./includes/libft/libft.h"
# include "./includes/ft_printf/ft_printf.h"

/*/		STACK MANAGEMENT		/*/
typedef struct s_node {
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_top {
	int		len;
	t_node	*top;
	t_node	*bottom;
}				t_top;

int		stack_len(t_top stack);
int		init_stack(t_top *stack);
int		free_stack(t_top *top_node);
int		fill_stack(t_top *stack_a, char **form_args);
int		add_on_top_or_bottom(t_top *stack, int val, int mode);
void	display_stack(t_top stack_a, char stack);

/*/		LOGICAL MOVEMENTS		/*/
void	swap(t_top *stack_a, t_top *stack_b, char swap);
void	push(t_top *stack_a, t_top *stack_b, char swap);
void	rotate(t_top *stack_a, t_top *stack_b, char swap);
void	rev_rotate(t_top *stack_a, t_top *stack_b, char swap);

static inline void	logic_swap(t_top *stack)
{
	t_node	*sec_node;
	t_node	*top_node;

	top_node = stack->top;
	sec_node = top_node->next;
	stack->top = sec_node;
	sec_node->prev = NULL;
	top_node->prev = sec_node;
	top_node->next = sec_node->next;
	sec_node->next = top_node;
}

static inline void	logic_push(t_top *stack_one, t_top *stack_two)
{
	t_node	*top_node_one;
	t_node	*top_node_two;

	top_node_one = stack_one->top;
	top_node_two = stack_two->top;
	stack_one->top = top_node_two;
	stack_two->top = top_node_two->next;
	if (top_node_one)
		top_node_one->prev = top_node_two;
	top_node_two->next = top_node_one;
	stack_one->len++;
	stack_two->len--;
}

static inline void	logic_rotate(t_top *stack)
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

static inline void	logic_reverse_rotate(t_top *stack)
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

/*/		PARSING MANAGEMENT		/*/

int		check_tab(char **form_args);
int		check_args(char **form_args);
char	**formate_args(int argc, char **argv);

/*/		RESOLVER & ALGO			/*/

int		resolver(t_top *stack_a, t_top *stack_b, int argc);

#endif