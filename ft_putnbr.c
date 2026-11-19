/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:55:50 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 14:55:52 by kmota            ###   ########.fr       */
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
