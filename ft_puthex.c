/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:55:40 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 15:58:05 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, const char c)
{
	char	*base;
	int		len;
	int		ret;

	base = 0;
	len = 0;
	ret = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ret = ft_puthex((n / 16), c);
		if (ret < 0)
			return (-1);
		len = ret;
	}
	ret = ft_putchar(base[n % 16]);
	if (ret < 0)
		return (-1);
	return (len + ret);
}
