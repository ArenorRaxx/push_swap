/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_addr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:51:53 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/06 17:44:12 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putpointer_addr(unsigned long long ptr)
{
	static int		flag;
	static char		*base = "0123456789abcdef";
	static size_t	lenbase = 16;

	if (!ptr)
	{
		ft_putstr("0x0");
		return ;
	}
	if (!flag++)
		ft_putstr("0x");
	if (ptr / lenbase != 0)
		ft_putpointer_addr(ptr / lenbase);
	ft_putchar(base[ptr % lenbase]);
	flag = 0;
}
