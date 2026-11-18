/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:25:25 by kmota             #+#    #+#             */
/*   Updated: 2026/11/18 15:48:09 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
#define FTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(char *s);
int	ft_numlen(long n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
long	ft_putnbr(int n);
int	ft_printf(const char *fm, ...);
unsigned int	ft_putunsig(long n);

#endif 