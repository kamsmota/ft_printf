/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:36:16 by kmota             #+#    #+#             */
/*   Updated: 2026/11/18 15:58:21 by kmota            ###   ########.fr       */
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
	int		v;
	long	u;
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
			else if (fm[i + 1] == 'd' || fm[i + 1] == 'i')
			{
				v = va_arg(args, int);
				total += ft_putnbr(v);
				i++;
			}
			else if (fm[i + 1] == '%')
			{
				total += ft_putchar('%');
				i++;
			}
			else if (fm[i + 1] == 'u')
			{
				u = va_arg(args, long);
				total += ft_putunsig(u);
				i++;
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
	int r;
	long c;
	
	c = 4294967295;
	ft = ft_printf("%u\n", c);
	r = printf("%li\n", c);

	printf("ft: %u\nreal: %u\n", ft, r);
}