/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:13:14 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/05 17:57:04 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	utils_set(int **set, int len)
{
	int	index;

	if (*set)
		free(*set);
	index = 0;
	*set = malloc(sizeof(**set) * (len + 1));
	if (!*set)
		return (-1);
	while (index < len)
		set[0][index++] = 1;
	set[0][index] = '\0';
	return (0);
}

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
}

int	check_set(int *set)
{
	int	i;
	int	push[2];

	if (!set)
		return (-1);
	i = 0;
	push[0] = 0;
	push[1] = 0;
	while (set[i] != '\0')
	{
		if (set[i] == 4)
			push[0]++;
		if (set[i] == 5)
			push[1]++;
		if (push[0] > push[1])
			return (-1);
		i++;
	}
	if (set[i - 1] == 5)
		return (-1);
	if (push[0] != push[1])
		return (-1);
	return (0);
}

int	next_set(int **set)
{
	int			index;
	static int	len = 1;

	index = 0;
	if (!*set)
	{
		if (utils_set(set, len) < 0)
			return (-1);
		return (len);
	}
	if (set[0][index] != 11)
	{
		set[0][index]++;
		return (len);
	}
	set[0][index] = 1;
	while (set[0][++index] == 11)
		set[0][index] = 1;
	if (set[0][index] != '\0')
	{
		set[0][index] += 1;
		return (len);
	}
	if (utils_set(set, ++len) < 0)
		return (-1);
	return (len);
}
