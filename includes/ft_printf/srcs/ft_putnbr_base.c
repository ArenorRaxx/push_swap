/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:00:43 by mcorso            #+#    #+#             */
/*   Updated: 2022/01/10 12:20:53 by mcorso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_base(long num, char *base, size_t lenbase)
{
	static int		sign;	

	if (num < 0 && sign == 0)
	{
		num *= -1;
		sign = 1;
	}
	if (num / lenbase != 0)
		ft_putnbr_base(num / lenbase, base, lenbase);
	if (sign)
	{
		ft_putchar('-');
		sign = 0;
	}
	ft_putchar(base[num % lenbase]);
}
