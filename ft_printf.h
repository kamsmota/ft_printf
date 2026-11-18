/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:25:25 by kmota             #+#    #+#             */
/*   Updated: 2026/11/18 20:50:49 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int				ft_putptr(void *ptr);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(long n);
int				ft_puthex(unsigned int n, const char c);
unsigned int	ft_putintus(unsigned long nb);
int				ft_printf(const char *fm, ...);

#endif 