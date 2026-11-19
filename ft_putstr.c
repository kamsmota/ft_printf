/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:56:00 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 15:50:23 by kmota            ###   ########.fr       */
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
		len = ft_putchar(s[i]);
		i++;
	}
	return (len);
}
