/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:02:46 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/23 14:02:40 by mcorso           ###   ########.fr       */
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

static int	check_for_pairs(int *set, int i)
{
	int	j;

	j = i + 1;
	if (set[i] <= 3 && set[j] <= 3)
		return (-1);
	else if ((set[i] == 4 && set[j] == 5) || (set[i] == 5 && set[j] == 4))
		return (-1);
	else if (set[i] == 6 && set[j] >= 7 && set[j] <= 11 && set[j] % 2 == 1)
		return (-1);
	else if (set[i] == 7 && (set[j] == 6 || set[j] == 10 || set[j] == 11))
		return (-1);
	else if (set[i] == 8 && set[j] >= 9 && set[j] <= 11)
		return (-1);
	else if (set[i] == 9 && (set[j] >= 6 && set[j] <= 10 && set[j] % 2 == 0))
		return (-1);
	else if (set[i] == 10 && set[j] >= 7 && set[j] <= 9)
		return (-1);
	else if (set[i] == 11 && set[j] >= 6 && set[j] <= 8)
		return (-1);
	return (0);
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
		if (check_for_pairs(set, i) < 0)
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
	}
	else if (set[0][index] != 11)
		set[0][index]++;
	else
	{
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
	}
	return (len);
}
