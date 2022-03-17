/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:14:51 by mcorso            #+#    #+#             */
/*   Updated: 2022/03/16 18:32:51 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

char	**formate_args(int argc, char **argv)
{
	int		i;
	char	**ret;

	i = 0;
	ret = NULL;
	if (argc == 2)
		ret = ft_split(argv[i], ' ');
	else if (argc > 2)
	{
		ret = malloc(sizeof(*ret) * (argc));
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
	int		arg;

	i = 0;
	while (form_args[i])
	{
		j = 0;
		while (form_args[i][j])
		{
			if (!(form_args[i][j] >= '0' && form_args[i][j] <= '9'))
				return (-1);
			j++;
		}
		j = 0;
		arg = ft_atoi(form_args[i]);
		while (j < i)
			if (arg == ft_atoi(form_args[j++]))
				return (-1);
		i++;
	}
	return (0);
}

int	check_args(char **form_args)
{
	if (form_args)
		if (!check_tab(form_args))
			return (0);
	return (-1);
}
