/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:36:16 by kmota             #+#    #+#             */
/*   Updated: 2026/11/17 22:37:49 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);	
}

int	ft_putstr(char *s)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (size);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_printf(const char *fm, ...)
{
	va_list	args;
	int		i;
	char	c;
	char	*s;
	long	total;

	i = 0;
	total = 0;
	va_start(args, fm);
	while (fm[i] != '\0')
	{
		if (fm[i] == '%' && fm[i + 1] != '\0')
		{
			if (fm[i + 1] == 'c')
			{
				c = (char)va_arg(args, int);
				total += ft_putchar(c);
				i++;
			}
			else if (fm[i + 1] == 's')
			{
				s = va_arg(args, char *);
				total += ft_putstr(s);
				i++;
			}
			else if (fm[i + 1] == '%')
			{
				total += ft_putchar('%');
				i++;
			}
			else
			{
				write(1, "%", 1);
				total++;
			}
			i++;
		}
		else
		{
			write(1, &fm[i], 1);
			i++;
			total++;
		}
	}
	va_end(args);
	return (total);
}

int main()
{
	int ft;
	//int r;

	ft = ft_printf("ola %c\n", 'x');
	//r = printf("ola %");

	printf("ft: %d", ft);

}