/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
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
	char	*arg;
	char	first_char;
	char	second_char;
	int		i;

	if (argc == 4 && !argv[2][1] && !argv[3][1])
	{
		arg = argv[1];
		first_char = argv[2][0];
		second_char = argv[3][0];
		i = 0;
		while (arg[i] != '\0')
		{
			if (arg[i] == first_char)
				arg[i] = second_char;
			ft_putchar(arg[i]);
			i ++;
		}
		ft_putchar('\n');
	}
	return (0);
}
