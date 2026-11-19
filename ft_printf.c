/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:56:13 by kmota             #+#    #+#             */
/*   Updated: 2026/11/19 17:11:18 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_porcent(const char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putintus(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	process_logic(const char *str, int *i, va_list *ap)
{
	int	val;

	if (str[*i] == '%' && str[*i + 1])
	{
		val = ft_porcent(str[*i + 1], ap);
		*i += 2;
	}
	else
	{
		val = ft_putchar(str[*i]);
		(*i)++;
	}
	return (val);
}

int	ft_printf(const char *fm, ...)
{
	va_list	args;
	int		i;
	int		total;
	int		ret;

	i = 0;
	ret = 0;
	total = 0;
	va_start(args, fm);
	while (fm[i] != '\0')
	{
		ret = process_logic(fm, &i, &args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		total += ret;
	}
	va_end(args);
	return (total);
}
