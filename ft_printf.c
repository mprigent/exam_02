#include <unistd.h>
#include <stdarg.h>

static int	nbrlen(long nb, int len)
{
	int	i = 1;
	while (nb >= len)
	{
		nb /= len;
		i++;
	}
	return (i);
}

static void	ft_putnbr(long nb, int len, char *base)
{
	if (nb >= len)
		ft_putnbr(nb / len, len, base);
	write(1, &base[nb % len], 1);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	char	*s;
	long	nb;
	int	neg;
	int	len;
	int	width;
	int	spaces;
	int	zeros;
	int	length = 0;

	va_start(args, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			neg = 0;
			len = 0;
			width = 0;
			spaces = 0;
			zeros = 0;
			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - 48);
				str++;
			}
			if (*str == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (s[len])
					len++;
			}
			if (*str == 'd')
			{
				nb = va_arg(args, int);
				if (nb < 0)
				{
					nb = -nb;
					neg = 1;
				}
				len = nbrlen(nb, 10) + neg;
			}
			if (*str == 'x')
			{
				nb = va_arg(args, unsigned);
				len = nbrlen(nb, 16);
			}
			spaces = width - zeros - len;
			while (spaces-- > 0)
				length += write(1, " ", 1);
			if (neg == 1)
				write(1, "-", 1);
			while (zeros-- > 0)
				length += write(1, "0", 1);
			if (*str == 's')
				write(1, s, len);
			else if (len > 0 && *str == 'd')
				ft_putnbr(nb, 10, "0123456789");
			else if (len > 0 && *str == 'x')
				ft_putnbr(nb, 16, "0123456789abcdef");
			length += len;
		}
		else
			length += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (length);
}
