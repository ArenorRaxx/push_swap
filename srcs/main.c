/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:15:46 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/27 15:12:20 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	error(t_top *stack_a, char *msg)
{
	free_stack(stack_a);
	ft_printf("%s\n", msg);
	exit (-1);
}

void	display_stack(t_top stack_a, char stack)
{
	t_node	*curr_node;

	curr_node = stack_a.top;
	ft_printf("Stack %c\n-------\n", stack);
	while (curr_node)
	{
		ft_printf("%i\n-------\n", curr_node->val);
		curr_node = curr_node->next;
	}
}

int	init(t_top *stack_a, int argc, char **argv, char ***formated_args)
{
	*formated_args = NULL;
	if (init_stack(stack_a) < 0)
		return (-1);
	*formated_args = formate_args(argc, argv);
	if (!formated_args)
		return (-1);
	if (check_args(*formated_args) < 0)
		return (-1);
	if (fill_stack(stack_a, *formated_args) < 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		err;
	char	**formated_args;
	t_top	stack_a;

	if (argc == 1)
		return (0);
	err = init(&stack_a, argc, argv, &formated_args);
	if (formated_args)
		free(formated_args);
	if (err < 0)
		return (error(&stack_a, "Error"));
	if (resolver(&stack_a, argc) < 0)
		return (error(&stack_a, "Malloc	Error"));
	free_stack(&stack_a);
	return (0);
}
