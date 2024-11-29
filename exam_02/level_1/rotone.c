/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
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

static	int	ft_isupper(char c)
{
	if ('A' <= c || c <= 'Y')
		return (1);
	return (0);
}

static	int	ft_islower(char c)
{
	if ('a' <= c || c <= 'y')
		return (1);
	return (0);
}

static	void	rotone(char *string)
{
	while (*string)
	{
		if (ft_islower(*string) || ft_isupper(*string))
			ft_putchar(*string + 1);
		else if ('z' == *string || *string == 'Z')
			ft_putchar(*string - 25);
		else
			ft_putchar(*string);
		string ++;
	}
}

int	main(int argc, char **argv)
{
	char	*arg;

	if (argc == 2)
	{
		arg = argv[1];
		rotone(arg);
		ft_putchar('\n');
	}
	return (0);
}
