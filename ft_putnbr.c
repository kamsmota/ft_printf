/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:41:18 by kams              #+#    #+#             */
/*   Updated: 2026/11/18 21:59:09 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	long	div;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	div = 1;
	while (nb / div > 9)
		div *= 10;
	while (div > 0)
	{
		len += ft_putchar((nb / div) + '0');
		nb %= div;
		div /= 10;
	}
	return (len);
}
