/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:17:10 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 21:05:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	EXIT_SUCCESS
#include <stdlib.h>
//	printf()
#include <stdio.h>

int	ft_printf(char *format, ...);

/**
 * @brief Tests ft_printf with NULL args.
 */
void	test_print_null_args(void)
{
	char	*format;
	int		printed;

	format = "(A)\tTest of NULL 's' format specifier: \"%s\"";
	printed = ft_printf(format, NULL);
	printf(" (%d)\n", printed);
	format = "(B)\tTest of NULL 's' format specifier: \"%s\"";
	printed = printf(format, NULL);
	printf(" (%d)\n", printed);
}

/**
 * @brief Tests ft_printf with a string without specifiers.
 */
void	test_print_no_specifiers(void)
{
	char	*format;
	int		printed;

	format = "(A)\tTest of string without format specifier";
	printed = ft_printf(format);
	printf(" (%d)\n", printed);
	format = "(B)\tTest of string without format specifier";
	printed = printf(format);
	printf(" (%d)\n", printed);
}

/**
 * @brief Tests printing functionality of 'x' format specifier.
 */
void	test_print_hexnum(void)
{
	char	*format;
	int		hexnum;

	hexnum = 1000;
	format = "(A)\tTest of (%d) hexnum format specifier: \"%x\"\n";
	ft_printf(format, hexnum, hexnum);
	format = "(B)\tTest of (%d) hexnum format specifier: \"%x\"\n";
	printf(format, hexnum, hexnum);
}

/**
 * @brief Tests printing functionality of 'd' format specifier.
 */
void	test_print_num(void)
{
	char	*format;
	int		number;

	number = 24;
	format = "(A)\tTest of number format specifier: \"%d\"\n";
	ft_printf(format, number);
	format = "(B)\tTest of number format specifier: \"%d\"\n";
	printf(format, number);
}

/**
 * @brief Tests printing functionality of 's' format specifier.
 */
void	test_print_str(void)
{
	char	*str;
	char	*format;

	str = "hello world string !?¿¡";
	format = "(A)\tTest of string format specifier: \"%s\"\n";
	ft_printf(format, str);
	format = "(B)\tTest of string format specifier: \"%s\"\n";
	printf(format, str);
}

/**
 * @brief Test 'd', 's', and 'x' format specifiers and compare with "printf()".
 */
void	test_print(void)
{
	ft_printf("Testing printing functionality of ft_printf...\n");
	test_print_str();
	test_print_num();
	test_print_hexnum();
}

/**
 * @brief Test return values of 'x' format specifier and compare with printf().
 */
void	test_return_hexnum(void)
{
	char	*format;
	int		hexnum;
	int		printed;

	hexnum = 1000;
	format = "(A)\t(%d) Hexnum format specifier: \"%x\"";
	printed = ft_printf(format, hexnum, hexnum);
	printf(" (%d)\n", printed);
	format = "(B)\t(%d) Hexnum format specifier: \"%x\"";
	printed = printf(format, hexnum, hexnum);
	printf(" (%d)\n", printed);
}

/**
 * @brief Test return values of 'd' format specifier and compare with printf().
 */
void	test_return_num(void)
{
	char	*format;
	int		number;
	int		printed;

	number = 24;
	format = "(A)\tNumber format specifier: \"%d\"";
	printed = ft_printf(format, number);
	printf(" (%d)\n", printed);
	format = "(B)\tNumber format specifier: \"%d\"";
	printed = printf(format, number);
	printf(" (%d)\n", printed);
}

/**
 * @brief Test return values of 's' format specifier and compare with printf().
 */
void	test_return_str(void)
{
	char	*str;
	char	*format;
	int		printed;

	str = "hello world string !?¿¡";
	format = "(A)\tString format specifier: \"%s\"";
	printed = ft_printf(format, str);
	printf(" (%d)\n", printed);
	format = "(B)\tString format specifier: \"%s\"";
	printed = printf(format, str);
	printf(" (%d)\n", printed);
}

/**
 * @brief Return values and compare with "printf()".
 */
void	test_return(void)
{
	ft_printf("Testing return value of ft_printf...\n");
	test_return_str();
	test_return_num();
	test_return_hexnum();
}

/**
 * @brief Perform basic tests on "ft_printf()" function.
 *
 * This is a basic functionality test and doesn't check edge cases.
 */
int	main(void)
{
	test_print();
	test_print_no_specifiers();
	test_print_null_args();
	test_return();
	return (EXIT_SUCCESS);
}
