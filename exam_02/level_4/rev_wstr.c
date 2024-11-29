/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
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
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static	void	ft_set_boundaries(char *arg, int *i, int *end, int *start)
{
	while (arg[*i] == '\0' || ft_isspace(arg[*i]))
		(*i)--;
	*end = *i;
	while (arg[*i] != '\0' && !ft_isspace(arg[*i]))
		(*i)--;
	*start = (*i) + 1;
}

static	void	ft_write_word(char *arg, int *end, int *start)
{
	int	aux;

	aux = *start;
	while (*start <= *end)
	{
		write(1, arg + (*start), 1);
		(*start)++;
	}
	if (aux != '\0')
		write(1, " ", 1);
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		start;
	int		end;
	int		i;

	if (argc != 2)
		return (1);
	arg = argv[1];
	i = 0;
	while (arg[i] != '\0')
		i ++;
	while (i >= 0)
	{
		ft_set_boundaries(arg, &i, &end, &start);
		ft_write_word(arg, &end, &start);
	}
	write(1, "\n", 1);
	return (0);
}
