/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	int	ft_isupper(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

static	int	ft_islower(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

static	char	ft_rot13(char c)
{
	if (ft_islower(c))
		return ((c - 'a' + 13) % 26 + 'a');
	else if (ft_isupper(c))
		return ((c - 'A' + 13) % 26 + 'A');
	return (c);
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		index;

	if (argc == 2)
	{
		arg = argv[1];
		index = 0;
		while (arg[index])
		{
			arg[index] = ft_rot13(arg[index]);
			write(1, arg + index, 1);
			index ++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
