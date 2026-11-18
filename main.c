#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int		ft;
	int		real;
	int		x;
	void	*m;

	x = 42;
	m = malloc(1);

	printf("===== TESTE %%c =====\n");
	ft = ft_printf("ft: %c\n", 'A');
	real = printf("ft: %c\n", 'A');
	printf("Retorno: ft=%d | real=%d\n\n", ft, real);

	printf("===== TESTE %%s =====\n");
	ft = ft_printf("ft: %s\n", "Hello World");
	real = printf("ft: %s\n", "Hello World");
	printf("Retorno: ft=%d | real=%d\n\n", ft, real);

	printf("===== TESTE %%p =====\n");
	ft = ft_printf("ft: %p %p %p\n", m, &x, "teste");
	real = printf("ft: %p %p %p\n", m, &x, "teste");
	printf("Retorno: ft=%d | real=%d\n\n", ft, real);

	printf("===== TESTE %%d e %%i =====\n");
	ft = ft_printf("ft: %d %i %d %i\n", 42, -42, 0, INT_MIN);
	real = printf("ft: %d %i %d %i\n", 42, -42, 0, INT_MIN);
	printf("Retorno: ft=%d | real=%d\n\n", ft, real);

	printf("===== TESTE %%u =====\n");
	ft = ft_printf("ft: %u %u %u\n", 0u, 42u, UINT_MAX);
	real = printf("ft: %u %u %u\n", 0u, 42u, UINT_MAX);
	printf("Retorno: ft=%d | real=%d\n\n", ft, real);

	printf("===== TESTE %%x e %%X =====\n");
	ft = ft_printf("ft: %x %X %x %X\n", 0, 255, 42, UINT_MAX);
	real = printf("ft: %x %X %x %X\n", 0, 255, 42, UINT_MAX);
	printf("Retorno: ft=%d | real=%d\n\n", ft, real);

	printf("===== TESTE %%%% =====\n");
	ft = ft_printf("ft: %% %%\n");
	real = printf("ft: %% %%\n");
	printf("Retorno: ft=%d | real=%d\n\n", ft, real);

	free(m);
	return (0);
}