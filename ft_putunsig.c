/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:46:58 by kmota             #+#    #+#             */
/*   Updated: 2026/11/18 15:57:12 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putunsig(long n)
{
	long			div;
	unsigned int	nb;
	
	nb = n;
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
