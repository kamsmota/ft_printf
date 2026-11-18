/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:41:18 by kams              #+#    #+#             */
/*   Updated: 2026/11/18 15:56:30 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_putnbr(int n)
{
	long	div;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	div = 1;
	while (nb / div > 9)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((nb / div) + '0');
		nb %= div;
		div /= 10;
	}
	return (ft_numlen(n));
}
