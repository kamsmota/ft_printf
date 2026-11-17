#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int ft;
	int r;

	ft = ft_printf("ola\n");
	r = printf("ola\n");

	printf("ft: %d, real: %d\n", ft, r);

}