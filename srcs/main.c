/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:15:46 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/17 10:33:12 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

int	error(void)
{
	ft_printf("Error\n");
	exit (-1);
}

int	main(int argc, char **argv)
{
	t_top	*stack_a;
	char	**formated_args;

	stack_a = NULL;
	if (init_stack(&stack_a) < 0)
		return (error());
	formated_args = formate_args(argc, argv);
	if (!formated_args)
		return (error());
	if (check_args(formated_args) < 0)
		return (error());
	if (fill_stack(stack_a, formated_args) < 0)
		return (error());
	free(formated_args);
	free_stack(stack_a);
}
