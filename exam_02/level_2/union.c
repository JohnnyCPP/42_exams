/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
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

static	void	ft_fill_with_zero(unsigned char *seen, const int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		seen[i] = 0;
		i ++;
	}
}

static	void	ft_iterate_arg(char *arg, unsigned char *seen)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!seen[(unsigned char) arg[i]])
		{
			ft_putchar(arg[i]);
			seen[(unsigned char) arg[i]] = 1;
		}
		i ++;
	}
}

int	main(int argc, char **argv)
{
	unsigned char	seen[256];
	char			*arg_1;
	char			*arg_2;

	if (argc == 3)
	{
		ft_fill_with_zero(seen, 256);
		arg_1 = argv[1];
		arg_2 = argv[2];
		ft_iterate_arg(arg_1, seen);
		ft_iterate_arg(arg_2, seen);
		ft_putchar('\n');
	}
	return (0);
}
