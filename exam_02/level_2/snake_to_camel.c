/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
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

static	int	ft_toupper(char c)
{
	int	offset;

	offset = 'a' - 'A';
	return (c - offset);
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		i;

	if (argc == 2)
	{
		arg = argv[1];
		i = 0;
		while (arg[i] != '\0')
		{
			if (arg[i] == '_')
			{
				i ++;
				arg[i] = ft_toupper(arg[i]);
			}
			ft_putchar(arg[i]);
			i ++;
		}
		ft_putchar('\n');
	}
	return (0);
}
