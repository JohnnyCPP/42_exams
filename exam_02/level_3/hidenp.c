/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
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

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg_1;
	char	*arg_2;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		arg_1 = argv[1];
		arg_2 = argv[2];
		while (arg_1[i] && arg_2[j])
		{
			if (arg_1[i] == arg_2[j])
				i ++;
			j ++;
		}
		if (arg_1[i] == '\0')
			ft_putchar('1');
		else
			ft_putchar('0');
		ft_putchar('\n');
	}
	return (0);
}
