/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:36:34 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/13 06:44:43 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	NULL
#include <stddef.h>
//	write()
#include <unistd.h>
//	malloc()
#include <stdlib.h>
//	va_list, va_start(), va_arg(), va_copy(), va_end()
#include <stdarg.h>
//	ft_itoa() needs it
#include <limits.h>

/**
 * @brief Prints a character to the stdout.
 *
 * @return 1 if writting was a success, -1 if an error occurred
 */
int	ft_putchar(char c)
{
	if (write(STDOUT_FILENO, &c, 1) == 1)
		return (1);
	return (0);
}

/**
 * @brief Prints a string to the stdout.
 *
 * @return The amount of characters printed.
 */
int	ft_putstr(char *str)
{
	int	i;
	int	printed;

	if (!str)
		return (0);
	i = 0;
	printed = 0;
	while (str[i])
	{
		printed += ft_putchar(str[i]);
		i ++;
	}
	return (i);
}

/**
 * @brief Computes the length of a string.
 *
 * @return The length of the string.
 */
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

/**
 * @brief Copies a string into a dynamically allocated one.
 *
 * @param str Target string to be copied from.
 *
 * @return Address of the new dynamically allocated copy.
 *         If "str" is NULL, or memory allocation fails, returns NULL.
 *
 * The returned string is null-terminated.
 */
char	*ft_strdup(const char *str)
{
	char	*strdup;
	int		i;

	if (!str)
		return (NULL);
	strdup = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i] != '\0')
	{
		strdup[i] = str[i];
		i ++;
	}
	strdup[i] = '\0';
	return (strdup);
}

/**
 * @brief Converts a number into a string.
 *
 * @param abs (Absolute) number to convert from.
 * @param numlen The amount of digits "abs" has.
 * @param sign Is 1 if "abs" is positive, -1 if negative.
 *
 * @return String version of "abs", dynamically allocated and null-terminated.
 *         If memory allocation falls, returns NULL.
 *         If "sign" equals -1, the string will be signed ('-').
 */
char	*ft_to_str(int abs, int numlen, const int sign)
{
	int		base;
	char	*itoa;

	base = 10;
	itoa = (char *) malloc(sizeof(char) * numlen + 1);
	if (!itoa)
		return (NULL);
	if (sign == -1)
		itoa[0] = '-';
	itoa[numlen] = '\0';
	numlen --;
	while (abs)
	{
		itoa[numlen] = (abs % base) + '0';
		abs /= base;
		numlen --;
	}
	return (itoa);
}

/**
 * @brief Computes the amount of digits in a decimal number.
 *
 * @param n The target number.
 *
 * @return The amount of digits in "n".
 */
int	ft_numlen(int n)
{
	int	base;
	int	numlen;

	base = 10;
	numlen = 0;
	if (n <= 0)
		numlen ++;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= base;
		numlen ++;
	}
	return (numlen);
}

/**
 * @brief Converts a number into a string.
 *
 * @param n The target number.
 *
 * @return "n" as a dynamically allocated string.
 *         If memory allocation fails, returns NULL.
 */
char	*ft_itoa(int n)
{
	long	abs;
	int		numlen;
	int		sign;

	if (!n)
		return (ft_strdup("0"));
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	numlen = ft_numlen(n);
	if (n < 0)
	{
		sign = -1;
		abs = -n;
	}
	else
	{
		sign = 1;
		abs = n;
	}
	return (ft_to_str(abs, numlen, sign));
}

/**
 * @brief Computes the amount of digits, of a hex version, of a decimal number.
 *
 * @param hexnum The target number.
 *
 * @return The amount of digits that the hex version of "hexnum" would have.
 */
int	ft_hexlen(unsigned int hexnum)
{
	unsigned int	base;
	int				i;

	base = 16;
	if (!hexnum)
		return (1);
	i = 0;
	while (hexnum)
	{
		hexnum /= base;
		i ++;
	}
	return (i);
}

/**
 * @brief Prints the hex version of a decimal number.
 *
 * @param hexnum The target number.
 */
void	ft_puthex(unsigned int hexnum)
{
	unsigned int	base;

	base = 16;
	if (hexnum >= base)
	{
		ft_puthex(hexnum / base);
		ft_puthex(hexnum % base);
	}
	else if (hexnum < 10)
		ft_putchar((char) hexnum + '0');
	else
		ft_putchar((char)(hexnum - 10) + 'a');
}

/**
 * @brief Gets the next variable argument, and prints a hexadecimal number.
 *
 * @param var_args List of variable arguments.
 *
 * @return The amount of digits printed.
 */
int	ft_print_hex(va_list var_args)
{
	unsigned int	hexnum;

	hexnum = va_arg(var_args, unsigned int);
	ft_puthex(hexnum);
	return (ft_hexlen(hexnum));
}

/**
 * @brief Gets the next variable argument, and prints a number to the stdout.
 *
 * @param var_args List of variable arguments.
 *
 * @return The amount of digits printed.
 */
int	ft_print_num(va_list var_args)
{
	char	*itoa;
	int		number;
	int		strlen;

	number = va_arg(var_args, int);
	itoa = ft_itoa(number);
	strlen = ft_putstr(itoa);
	if (itoa)
		free(itoa);
	return (strlen);
}

/**
 * @brief Gets the next variable argument, and prints a string to the stdout.
 *
 * @param var_args List of variable arguments.
 *
 * @return The amount of characters printed.
 */
int	ft_print_str(va_list var_args)
{
	char	*str;

	str = va_arg(var_args, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

/**
 * @brief Handles the next 's', 'd', or 'x' format specifier.
 *
 * @param format The format string at the current format specifier.
 * @param var_args List of variable arguments.
 * @param i Address to the current index of "format".
 *
 * @return The amount of characters printed.
 *
 * This function handles printing a format string to the stdout.
 * It supports 's', 'd', and 'x' format specifiers, fetching the 
 * variable arguments and printing their values depending on the specifiers.
 *
 * If the current character is a '%' but the next character is not a 
 * supported format specifier, it will print it as a literal character.
 */
int	ft_handle_format(const char *format, va_list var_args, int *i)
{
	if (format[1] == 's')
	{
		*i += 2;
		return (ft_print_str(var_args));
	}
	else if (format[1] == 'd')
	{
		*i += 2;
		return (ft_print_num(var_args));
	}
	else if (format[1] == 'x')
	{
		*i += 2;
		return (ft_print_hex(var_args));
	}
	else
	{
		(*i)++;
		return (ft_putchar('%'));
	}
}

/**
 * @brief A variadic function that prints formatted output to the stdout.
 *
 * @param format Is a string that specifies the format of the output.
 * @param "..." Are variadic arguments.
 *
 * @return The amount of characters printed.
 *         If "format" is not a valid pointer, returns -1.
 */
int	ft_printf(char const *format, ...)
{
	va_list	var_args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(var_args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_handle_format(&format[i], var_args, &i);
		else
		{
			count += ft_putchar(format[i]);
			i ++;
		}
	}
	va_end(var_args);
	return (count);
}
