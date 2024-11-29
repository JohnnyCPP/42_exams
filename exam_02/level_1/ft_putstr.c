/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

void	ft_putstr(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		write(1, &string[index], 1);
		index ++;
	}
}

int	main(int argc, char **argv)
{
	char	*first_argument;

	if (argc == 2)
	{
		first_argument = argv[1];
		ft_putstr(first_argument);
		write(1, "\n", 1);
	}
	return (0);
}
