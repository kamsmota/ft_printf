/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:41:18 by kams              #+#    #+#             */
/*   Updated: 2026/11/18 23:17:27 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		len++;
		nb = -nb;
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	if (ft_putchar((nb % 10) + '0') < 0)
		return (-1);
	return (len + 1);
}
