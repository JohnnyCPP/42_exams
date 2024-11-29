/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	int	ft_isspace(char *c, int i)
{
	if (c[i] == ' ' || c[i] == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	iterator;

	iterator = 0;
	if (argc == 2)
	{
		while (ft_isspace(argv[1], iterator))
			iterator ++;
		while (!ft_isspace(argv[1], iterator) && argv[1][iterator])
		{
			write(1, &argv[1][iterator], 1);
			iterator ++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
