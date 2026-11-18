/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:43:57 by kmota             #+#    #+#             */
/*   Updated: 2026/11/18 23:13:19 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		len;
	int		res;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	res = 0;
	while (s[i])
	{
		res = ft_putchar(s[i]);
		if (res < 0)
			return (-1);
		len += res;
		i++;
	}
	return (len);
}
