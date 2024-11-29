/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
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

static	void	ft_iterate_arg_1(char *arg_1, char *arg_2, unsigned char seen[])
{
	int	i;
	int	j;

	i = 0;
	while (arg_1[i])
	{
		j = 0;
		while (arg_2[j])
		{
			if (arg_1[i] == arg_2[j])
			{
				if (!seen[(unsigned char) arg_1[i]])
				{
					ft_putchar(arg_1[i]);
					seen[(unsigned char) arg_1[i]] = 1;
				}
				break ;
			}
			j ++;
		}
		i ++;
	}
}

int	main(int argc, char **argv)
{
	unsigned char	seen[256];
	char			*arg_1;
	char			*arg_2;
	int				i;

	i = 0;
	if (argc == 3)
	{
		while (i < 256)
		{
			seen[i] = 0;
			i ++;
		}
		arg_1 = argv[1];
		arg_2 = argv[2];
		ft_iterate_arg_1(arg_1, arg_2, seen);
		ft_putchar('\n');
	}
	return (0);
}
