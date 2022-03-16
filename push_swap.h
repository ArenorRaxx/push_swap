/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:31:50 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/16 17:22:25 by mcorso           ###   ########.fr       */
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
	t_node	*top;
	t_node	*bottom;
}				t_top;

int		init_stack(t_top *stack);
int		free_stack(t_top top_node);
int		add_on_stack(t_top *stack, int val);
t_node	*top_or_bottom(t_node node, int mode);

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

/*/		PARSING MANAGEMENT		/*/

int		check_tab(char **form_args);
int		check_args(int argc, char **argv);
char	**formate_args(int argc, char **argv);

static inline void	double_tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

#endif