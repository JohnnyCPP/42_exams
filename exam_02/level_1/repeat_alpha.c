/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	write()
#include <unistd.h>

static	int	ft_isupper(char character)
{
	if ('A' <= character && character <= 'Z')
		return (1);
	return (0);
}

static	int	ft_islower(char character)
{
	if ('a' <= character && character <= 'z')
		return (1);
	return (0);
}

static	void	ft_handle_print(const char *arg, int *index, int *count)
{
	if (ft_islower(arg[*index]))
		*count = arg[*index] - 'a' + 1;
	else if (ft_isupper(arg[*index]))
		*count = arg[*index] - 'A' + 1;
	else
		*count = 1;
	while (*count != 0)
	{
		write(1, arg + *index, 1);
		(*count)--;
	}
	(*index)++;
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		index;
	int		count;

	if (argc == 2)
	{
		arg = argv[1];
		index = 0;
		while (arg[index] != '\0')
			ft_handle_print(arg, &index, &count);
		write(1, "\n", 1);
	}
	return (0);
}
