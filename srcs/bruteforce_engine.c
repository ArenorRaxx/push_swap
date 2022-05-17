/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:13:14 by mcorso            #+#    #+#             */
/*   Updated: 2022/04/26 17:55:32 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	utils_set(char **set, int len)
{
	int	index;

	if (*set)
		free(*set);
	index = 0;
	*set = malloc(sizeof(**set) * (len + 1));
	if (!*set)
		return (-1);
	while (index < len)
		*set[index++] = 1;
	*set[index] = '\0';
	return (0);
}

int	next_set(char **set)
{
	int			index;
	static int	len = 1;

	index = 0;
	if (!*set)
	{
		if (utils_set(set, len) < 0)
			return (-1);
	}
	else
		*set[index] += 1;
	if (*set[index] > 11)
	{
		*set[index] = 1;
		while (*set[++index] == 11)
			*set[index] = 1;
		if (*set[index] == '\0')
		{
			if (utils_set(set, ++len) < 0)
				return (-1);
		}
		else
			*set[index] += 1;
	}
	return (0);
}

void	pseudo_exec(char *set, t_top tmp_a)
{
	int		i;
	t_top	tmp_b;

	i = 0;
	tmp_b.len = 0;
	while (set[i] != '\0')
	{
		ft_printf("%i\n", set[i]);
		if (set[i] == 1 || set[i] == 3)
			swap(&tmp_a, &tmp_b, 'a', 1);
		if (set[i] == 2 || set[i] == 3)
			swap(&tmp_a, &tmp_b, 'b', 1);
		if (set[i] == 4)
			push(&tmp_a, &tmp_b, 'a', 1);
		if (set[i] == 5)
			push(&tmp_a, &tmp_b, 'b', 1);
		if (set[i] == 6 || set[i] == 8)
			rotate(&tmp_a, &tmp_b, 'a', 1);
		if (set[i] == 7 || set[i] == 8)
			rotate(&tmp_a, &tmp_b, 'b', 1);
		if (set[i] == 9 || set[i] == 11)
			rev_rotate(&tmp_a, &tmp_b, 'a', 1);
		if (set[i] == 10 || set[i] == 11)
			rev_rotate(&tmp_a, &tmp_b, 'b', 1);
		i++;
	}
	ft_printf("ok\n");
}

void	rev_pseudo_exec(char *set, t_top tmp_a)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = 0;
	while (set[len] != '\0')
	{
		if (set[len] == 4 || set[len] == 5)
			set[len] += 1 * (-1 * (set[len] % 4));
		else if (set[len] >= 6 && set[len] <= 8)
			set[len] += 3;
		else if (set[len] >= 9 && set[len] <= 11)
			set[len] -= 3;
		len++;
	}
	while (i < len--)
	{
		tmp = set[i];
		set[i] = set[len];
		set[len] = tmp;
		i++;
	}
	pseudo_exec(set, tmp_a);
}
