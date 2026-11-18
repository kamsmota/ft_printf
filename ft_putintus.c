/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:46:58 by kmota             #+#    #+#             */
/*   Updated: 2026/11/18 22:15:10 by kams             ###   ########.fr       */
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
