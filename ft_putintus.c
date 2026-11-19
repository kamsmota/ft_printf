/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:55:45 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 14:55:47 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putintus(unsigned int nb)
{
	long	div;
	int		len;

	len = 0;
	div = 1;
	while (nb / div > 9)
		div *= 10;
	while (div > 0)
	{
		ft_putchar((nb / div) + '0');
		len++;
		nb %= div;
		div /= 10;
	}
	return (len);
}
