/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:31:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/14 13:49:01 by mcorso           ###   ########.fr       */
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
void	display_stack(t_top stack_a, char stack);

/*/		MOVES MANAGEMENT		/*/
void	swap(t_top *stack_a, t_top *stack_b, char swap, int pseudo);
void	push(t_top *stack_a, t_top *stack_b, char swap, int pseudo);
void	rotate(t_top *stack_a, t_top *stack_b, char swap, int pseudo);
void	rev_rotate(t_top *stack_a, t_top *stack_b, char swap, int pseudo);

static inline void	logic_swap(t_top *stack)
{
	t_node	*top_node;
	t_node	*sec_node;
	t_node	*thd_node;

	top_node = stack->top;
	sec_node = top_node->next;
	thd_node = sec_node->next;
	top_node->prev = sec_node;
	top_node->next = thd_node;
	sec_node->prev = NULL;
	sec_node->next = top_node;
	if (thd_node)
		thd_node->prev = top_node;
	else
		stack->bottom = top_node;
	stack->top = sec_node;
}

static inline void	logic_push(t_top *stack_one, t_top *stack_two)
{
	t_node	*top_node_one;
	t_node	*top_node_two;
	t_node	*new_top_node;

	top_node_one = stack_one->top;
	top_node_two = stack_two->top;
	new_top_node = top_node_two->next;
	top_node_two->next = top_node_one;
	if (top_node_one)
		top_node_one->prev = top_node_two;
	else
		stack_one->bottom = top_node_two;
	if (new_top_node)
		new_top_node->prev = NULL;
	stack_one->top = top_node_two;
	stack_two->top = new_top_node;
	stack_one->len++;
	stack_two->len--;
}

static inline void	logic_rotate(t_top *stack)
{
	t_node	*top_node;
	t_node	*sec_node;
	t_node	*bot_node;

	top_node = stack->top;
	sec_node = top_node->next;
	bot_node = stack->bottom;
	top_node->prev = bot_node;
	top_node->next = NULL;
	sec_node->prev = NULL;
	bot_node->next = top_node;
	stack->top = sec_node;
	stack->bottom = top_node;
}

static inline void	logic_reverse_rotate(t_top *stack)
{
	t_node	*top_node;
	t_node	*prebot_node;
	t_node	*bot_node;

	top_node = stack->top;
	prebot_node = stack->bottom->prev;
	bot_node = stack->bottom;
	bot_node->prev = NULL;
	bot_node->next = top_node;
	prebot_node->next = NULL;
	top_node->prev = bot_node;
	stack->top = bot_node;
	stack->bottom = prebot_node;
}

/*/		PARSING MANAGEMENT		/*/
int		check_tab(char **form_args);
int		check_args(char **form_args);
char	**formate_args(int argc, char **argv);

/*/		RESOLVER & ALGO			/*/
int		is_sorted(t_top stack_a);
int		resolver(t_top *stack_a, int argc);
//		Move set management
int		next_set(int **set);
int		check_set(int *set);
//		Bruteforce engine
int		brute_force(t_top *stack_a, t_top *stack_b);
int		rev_pseudo_exec(int *set, int set_len, t_top *tmp_a, t_top *tmp_b);
void	pseudo_exec(int *set, t_top *tmp_a, t_top *tmp_b, int pseudo);

#endif