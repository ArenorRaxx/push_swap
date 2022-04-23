/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:03:28 by mcorso            #+#    #+#             */
/*   Updated: 2022/04/23 10:53:34 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static int	create_inst_node(t_inst *new_instruct)
{
	new_instruct = malloc(sizeof(*new_instruct));
	if (!new_instruct)
		return (-1);
	new_instruct->instruct = NULL;
	new_instruct->prev = NULL;
	new_instruct->next = NULL;
	return (0);
}

static int	add_instruct(t_inst *prev, char *instruct)
{
	t_inst	*new_instruct;

	if (create_inst_node(new_instruct) < 0)
		return (-1);
	new_instruct->instruct = instruct;
	new_instruct->prev = prev;
	prev->next = new_instruct;
	return (0);
}

static void	free_from(t_inst *from)
{
	t_inst	*tmp;

	from->prev->next = NULL;
	while (from)
	{
		tmp = from;
		from = from->next;
		free(tmp);
	}
}

int	manage_instruct(t_intop *instruct, char **set)
{
	int		i;
	int		j;
	t_inst	*tmp;
	t_inst	*curr_node;

	i = 0;
	curr_node = instruct->top;
	while (ft_strncmp(set[i++], curr_node->instruct, 3) == 0 && curr_node)
		curr_node = curr_node->next;
	if (curr_node)
	{
		tmp = curr_node->prev;
		free_from(curr_node);
		while (set[i])
		{
			if (add_instruct(tmp, set[i]) < 0)
				return (-1);
			tmp = tmp->next;
		}
	}
	return (0);
}
