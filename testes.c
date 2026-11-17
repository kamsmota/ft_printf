#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void	say(const char *tpl, ...)
{
	va_list	ap;
	int		i;
	char	c;
	char	*s;

	va_start(ap, tpl);
	i = 0;
	while (tpl[i] != '\0')
	{
		if (tpl[i] == '%' && tpl[i + 1] != '\0')
		{
			if (tpl[i + 1] == 's')
			{
				s = va_arg(ap, char *);
				write(1, s, strlen(s));
				i++;
			}
		}
		else if (tpl[i] == 'd')
		{
			c = (char)va_arg(ap, int);
			write(1, &c, 1);
		}
		else
			write(1, &tpl[i], 1);
		i++;
	}
	va_end(ap);
}

int main  ()
{
	say("ola %s, nota: d\n", "mund", '5');
}