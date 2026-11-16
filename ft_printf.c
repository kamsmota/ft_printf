/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmota <kmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:36:16 by kmota             #+#    #+#             */
/*   Updated: 2026/11/16 15:14:52 by kmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *a, ...)
{
	va_list args; // guarda o estado da leitura dos argumentos variaveis, em que ponto da lista estamos
	
	va_start(args, a); // inicializa o va_list com args, o segundo parametro eh o ultimo parametro que conhecemos da funcao (nesse caso *a)
}