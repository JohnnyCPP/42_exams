/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	int	ft_isprintable(char c)
{
	if ('!' <= c && c <= '~')
		return (1);
	return (0);
}

static	int	ft_isword(char *str)
{
	char	current;
	char	next;

	current = *str;
	next = *(str + 1);
	if (current == ' ' && ft_isprintable(next))
		return (1);
	return (0);
}

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	void	last_word(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isword(str + i))
			j = i + 1;
		i ++;
	}
	while (ft_isprintable(str[j]))
	{
		ft_putchar(str[j]);
		j ++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	return (0);
}
