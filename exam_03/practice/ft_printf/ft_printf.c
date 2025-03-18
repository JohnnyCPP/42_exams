#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_putchar(const char c)
{
	return ((int) write(STDOUT_FILENO, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	printed;
	int	count;
	int	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		printed = ft_putchar(str[i]);
		if (printed != -1)
			count += printed;
		i ++;
	}
	return (count);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

int	ft_numlen(int n)
{
	int	base;
	int	numlen;

	base = 10;
	numlen = 0;
	if (!n)
		return (1);
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= base;
		numlen ++;
	}
	return (numlen);
}

int	ft_hexlen(unsigned int hexnum)
{
	int	base;
	int	hexlen;

	base = 16;
	if (!hexnum)
		return (1);
	hexlen = 0;
	while (hexnum)
	{
		hexnum /= base;
		hexlen ++;
	}
	return (hexlen);
}

char	*ft_strcpy(const char *str)
{
	char	*strcpy;
	int	i;

	if (!str)
		return (NULL);
	strcpy = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!strcpy)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		strcpy[i] = str[i];
		i ++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}

int	ft_print_str(va_list va_args)
{
	char	*str;

	str = va_arg(va_args, char *);
	if (!str)
		str = "(null)";
	return (ft_putstr(str));
}

char	*ft_to_str(int abs, int sign, int numlen)
{
	int	base;
	char	*itoa;

	base = 10;
	itoa = (char *) malloc(sizeof(char) * numlen + 1);
	if (!itoa)
		return (NULL);
	if (sign == -1)
		itoa[0] = '-';
	itoa[numlen] = '\0';
	while (abs)
	{
		itoa[numlen - 1] = (abs % base) + '0';
		numlen --;
		abs /= base;
	}
	return (itoa);
}

char	*ft_itoa(int n)
{
	int	numlen;
	int	sign;
	int	abs;

	if (!n)
		return (ft_strcpy("0"));
	else if (n == INT_MIN)
		return (ft_strcpy("-2147483648"));
	numlen = ft_numlen(n);
	if (n < 0)
	{
		sign = -1;
		abs = -n;
		numlen ++;
	}
	else
	{
		sign = 1;
		abs = n;
	}
	return (ft_to_str(abs, sign, ft_numlen(n)));
}

int	ft_print_number(va_list va_args)
{
	int	count;
	int	number;
	char	*itoa;

	number = va_arg(va_args, int);
	itoa = ft_itoa(number);
	count = ft_putstr(itoa);
	if (itoa)
		free(itoa);
	return (count);
}

int	ft_puthex(unsigned int hexnum)
{
	int	base;
	int	hexlen;

	base = 16;
	hexlen = ft_hexlen(hexnum);
	/*
	if (15 < hexnum)
	{
		ft_puthex(hexnum / base);
		ft_puthex(hexnum % base);
	}
	else if (9 < hexnum)
	*/
	(void) base;
	(void) hexlen;
	return (0);
}

int	ft_print_hexnum(va_list va_args)
{
	unsigned int	hexnum;

	hexnum = va_arg(va_args, unsigned int);
	return (ft_puthex(hexnum));
}

int	ft_handle_format(const char *format, va_list va_args, int *i)
{
	if (format[(*i) + 1] == 's')
	{
		(*i) += 2;
		return (ft_print_str(va_args));
	}
	else if (format[(*i) + 1] == 'd')
	{
		(*i) += 2;
		return (ft_print_number(va_args));
	}
	else if (format[(*i) + 1] == 'x')
	{
		(*i) += 2;
		return (ft_print_hexnum(va_args));
	}
	else if (format[(*i) + 1] == '%')
	{
		(*i) += 2;
		return (ft_putchar('%'));
	}
	else
	{
		ft_putchar(format[*i]);
		(*i)++;
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	va_args;
	int	i;
	int	count;

	va_start(va_args, format);
	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_handle_format(format, va_args, &i);
		else
		{
			count += ft_putchar(format[i]);
			i ++;
		}
	}
	va_end(va_args);
	return (count);
}
