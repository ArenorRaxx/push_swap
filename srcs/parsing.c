/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:14:51 by mcorso            #+#    #+#             */
/*   Updated: 2022/06/27 15:12:00 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**formate_args(int argc, char **argv)
{
	int		i;
	char	**ret;

	i = 0;
	ret = NULL;
	if (argc >= 2)
	{
		ret = malloc(sizeof(*ret) * argc);
		if (!ret)
			return (NULL);
		while (++i < argc)
			ret[i - 1] = argv[i];
		ret[i - 1] = NULL;
	}
	return (ret);
}

int	check_tab(char **form_args)
{
	int		i;
	int		j;
	long	arg;

	i = -1;
	while (form_args[++i])
	{
		j = 0;
		while (form_args[i][j])
		{
			if (!ft_isdigit(form_args[i][j]) &&
				!((form_args[i][j] == '-' || form_args[i][j] == '+') &&
					ft_isdigit(form_args[i][j + 1])))
				return (-1);
			j++;
		}
		j = 0;
		arg = ft_atoi(form_args[i]);
		if (arg > 2147483647 || arg < -2147483648)
			return (-1);
		while (j < i)
			if (arg == ft_atoi(form_args[j++]))
				return (-1);
	}
	return (0);
}

int	check_args(char **form_args)
{
	if (form_args)
		if (check_tab(form_args))
			return (-1);
	return (0);
}
