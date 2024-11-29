/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
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

static	void	ft_iterate_arg_1(char *arg_1, int i)
{
	if (arg_1[i] == '\0')
	{
		i = 0;
		while (arg_1[i] != '\0')
		{
			ft_putchar(arg_1[i]);
			i ++;
		}
	}
	ft_putchar('\n');
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
		while (arg_2[j] != '\0')
		{
			if (arg_1[i] == arg_2[j])
				i ++;
			j ++;
		}
		ft_iterate_arg_1(arg_1, i);
	}
	return (0);
}
