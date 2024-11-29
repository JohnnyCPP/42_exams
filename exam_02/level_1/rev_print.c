/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

char	*rev_print(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index ++;
	while (index >= 0)
	{
		index --;
		write(1, str + index, 1);
	}
	write(1, "\n", 1);
	return (str);
}

int	main(int argc, char **argv)
{
	char	*arg;

	if (argc == 2)
	{
		arg = argv[1];
		rev_print(arg);
	}
	return (0);
}
