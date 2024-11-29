/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	int	ft_isuppercase(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

static	int	ft_isendofword(char *c)
{
	char	current;
	char	next;

	current = *c;
	next = *(c + 1);
	if ('a' <= current && current <= 'z')
		if (next == ' ' || next == '\t' || next == '\0')
			return (1);
	return (0);
}

static	void	rstr_capitalizer(char *str)
{
	int	i;
	int	offset;

	i = 0;
	offset = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (ft_isuppercase(str[i]))
			str[i] += offset;
		if (ft_isendofword(str + i))
			str[i] -= offset;
		ft_putchar(str[i]);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		rstr_capitalizer(argv[i]);
		ft_putchar('\n');
		i ++;
	}
	return (0);
}
