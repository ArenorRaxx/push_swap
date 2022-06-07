/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:13:14 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/06 15:08:52 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pseudo_exec(int *set, t_top *tmp_a, t_top *tmp_b, int pseudo)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == 1 || set[i] == 3)
			swap(tmp_a, tmp_b, 'a', pseudo);
		if (set[i] == 2 || set[i] == 3)
			swap(tmp_a, tmp_b, 'b', pseudo);
		if (set[i] == 4)
			push(tmp_a, tmp_b, 'a', pseudo);
		if (set[i] == 5)
			push(tmp_a, tmp_b, 'b', pseudo);
		if (set[i] == 6 || set[i] == 8)
			rotate(tmp_a, tmp_b, 'a', pseudo);
		if (set[i] == 7 || set[i] == 8)
			rotate(tmp_a, tmp_b, 'b', pseudo);
		if (set[i] == 9 || set[i] == 11)
			rev_rotate(tmp_a, tmp_b, 'a', pseudo);
		if (set[i] == 10 || set[i] == 11)
			rev_rotate(tmp_a, tmp_b, 'b', pseudo);
		i++;
	}
}

int	rev_pseudo_exec(int *set, int set_len, t_top *tmp_a, t_top *tmp_b)
{
	int		len;
	int		*rev_set;

	len = 0;
	rev_set = malloc(sizeof(*rev_set) * (set_len + 1));
	if (!rev_set)
		return (-1);
	rev_set[set_len] = '\0';
	while (set_len--)
	{
		if (set[len] == 4 || set[len] == 5)
			rev_set[set_len] = set[len] - (set[len] == 5) + (set[len] == 4);
		else if (set[len] >= 6 && set[len] <= 8)
			rev_set[set_len] = set[len] + 3;
		else if (set[len] >= 9 && set[len] <= 11)
			rev_set[set_len] = set[len] - 3;
		else
			rev_set[set_len] = set[len];
		len++;
	}
	pseudo_exec(rev_set, tmp_a, tmp_b, 1);
	return (0);
}

int	brute_force(t_top *stack_a)
{
	int			set_len;
	t_top		stack_b;
	static int	*set;

	set_len = 0;
	stack_b.len = 0;
	stack_b.top = NULL;
	stack_b.bottom = NULL;
	while (is_sorted(*stack_a) < 0)
	{
		if (set)
			if (rev_pseudo_exec(set, set_len, stack_a, &stack_b) < 0)
				return (-1);
		while (1)
		{
			set_len = next_set(&set);
			if (set_len < 0)
				return (-1);
			if (check_set(set) < 0)
				continue ;
			break ;
		}
		pseudo_exec(set, stack_a, &stack_b, 1);
	}
	pseudo_exec(set, stack_a, &stack_b, 0);
	return (0);
}
