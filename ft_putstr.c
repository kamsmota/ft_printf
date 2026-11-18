/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:43:57 by kmota             #+#    #+#             */
/*   Updated: 2026/11/18 21:58:09 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		len;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}
