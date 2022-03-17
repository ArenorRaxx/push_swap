/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:15:46 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/17 17:22:43 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

int	error(void)
{
	ft_printf("Error\n");
	exit (-1);
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
	t_top	stack_b;

	err = init(&stack_a, argc, argv, &formated_args);
	if (formated_args)
		free(formated_args);
	if (err < 0)
		return (error());
	display_stack(stack_a);
	free_stack(&stack_a);
}
