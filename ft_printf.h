/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kams <kams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:25:25 by kmota             #+#    #+#             */
/*   Updated: 2026/11/17 21:11:43 by kams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
#define FTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf(const char *fm, ...);

#endif 