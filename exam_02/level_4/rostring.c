/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	void	ft_write_word(char *start, char *end)
{
	while (start < end)
	{
		write(1, start, 1);
		start ++;
	}
}

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static	void	ft_set_boundaries(char **arg, char **start, char **end)
{
	while (ft_isspace(**arg))
		(*arg)++;
	*start = *arg;
	while (**arg != '\0' && !ft_isspace(**arg))
		(*arg)++;
	*end = *arg;
	while (ft_isspace(**arg))
		(*arg)++;
}

static	void	ft_write_rest(char *arg)
{
	while (*arg != '\0')
	{
		if (ft_isspace(*arg))
		{
			while (ft_isspace(*arg))
				arg ++;
			if (*arg != '\0')
				write(1, " ", 1);
		}
		else
		{
			write(1, arg, 1);
			arg ++;
		}
	}
	write(1, " ", 1);
}

int	main(int argc, char **argv)
{
	char	*arg;
	char	*start;
	char	*end;

	if (argc != 2)
		return (1);
	arg = argv[1];
	ft_set_boundaries(&arg, &start, &end);
	if (*arg != '\0')
		ft_write_rest(arg);
	ft_write_word(start, end);
	write(1, "\n", 1);
	return (0);
}
