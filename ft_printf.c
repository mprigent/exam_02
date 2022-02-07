#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while(str && str[i])
		i++;
	return (i);
}

static int nbrlen(long nb, int len)
{
	int	i = 1;
	if (nb < 0)
		nb = -nb;
	while (nb >= len)
	{
		nb /= len;
		i++;
	}
	return (i);
}

static void ft_putnbr(long nb, char *base)
{
	const size_t len = ft_strlen(base);

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb / len > 0)
		ft_putnbr(nb / len, base);
	write(1, &base[nb % len], 1);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	char	*s;
	long	nb;
	int	len;
	int	length = 0;

	va_start(args, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len = 0;
			if (*str == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (s[len])
				{
					ft_putchar(s[len]);
					len++;
				}
			}
			else if (*str == 'd')
			{
				nb = va_arg(args, int);
				ft_putnbr(nb, "0123456789");
				len = nbrlen(nb, 10) + (nb < 0);
			}
			else if (*str == 'x')
			{
				nb = va_arg(args, unsigned);
				ft_putnbr(nb, "0123456789abcdef");
				len = nbrlen(nb, 16);
			}
			length += len;
		}
		else
		{
			length++;
			ft_putchar(*str);
		}
		str++;
	}
	va_end(args);
	return (length);
}
