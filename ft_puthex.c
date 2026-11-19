/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:55:40 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 14:55:43 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, const char c)
{
	char	*base;
	int		len;

	base = 0;
	len = 0;
	if (c == 'x')
	{
		base = "0123456789abcdef";
	}
	else if (c == 'X')
	{
		base = "0123456789ABCDEF";
	}
	if (n >= 16)
	{
		len += ft_puthex((n / 16), c);
	}
	len += ft_putchar(base[n % 16]);
	return (len);
}
