/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	int	ft_isspace(char c)
{
	if (' ' == c || c == '\t')
		return (1);
	return (0);
}

static	void	ft_puttext(char *arg, int *i, int *space_found)
{
	if (ft_isspace(arg[*i]))
		*space_found = 1;
	else
	{
		if (*space_found)
			write(1, "   ", 3);
		*space_found = 0;
		write(1, arg + *i, 1);
	}
	(*i)++;
}

int	main(int argc, char **argv)
{
	int		i;
	int		space_found;
	char	*arg;

	if (argc == 2)
	{
		i = 0;
		space_found = 0;
		arg = argv[1];
		while (ft_isspace(arg[i]))
			i ++;
		while (arg[i] != '\0')
			ft_puttext(arg, &i, &space_found);
		write(1, "\n", 1);
	}
	return (0);
}
