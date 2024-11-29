/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
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

static	int	ft_islower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

static	int	ft_isupper(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
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
			if (ft_islower(arg[i]))
				arg[i] -= 32;
			else if (ft_isupper(arg[i]))
				arg[i] += 32;
			ft_putchar(arg[i]);
			i ++;
		}
		ft_putchar('\n');
	}
	return (0);
}
