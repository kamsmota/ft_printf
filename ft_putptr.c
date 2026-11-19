/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:55:55 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 14:55:57 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	len = ft_putstr("0x");
	len += ft_puthex((uintptr_t)ptr, 'x');
	return (len);
}
