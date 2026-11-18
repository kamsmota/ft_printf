/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:48:05 by kams              #+#    #+#             */
/*   Updated: 2026/11/18 20:34:59 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, const char c)
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
