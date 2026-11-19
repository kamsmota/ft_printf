/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:56:00 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 15:54:16 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		len;
	int		ret;

	i = 0;
	ret = 0;
	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[i])
	{
		ret = ft_putchar(s[i]);
		if (ret < 0)
			return (-1);
		len = ret;
		i++;
	}
	return (len);
}
