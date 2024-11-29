/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	printf()
#include <stdio.h>
//	free()
#include <stdlib.h>

char	**ft_split(char *str);

//	iterate result and print each string
static	void	ft_print_result(char **result)
{
	char	**i;
	char	*string;

	i = result;
	while (*i != NULL)
	{
		string = *i;
		printf("%s\n", string);
		i ++;
	}
}

//	iterate result and free each string
static	void	ft_free_result(char **result)
{
	char	**i;
	char	*string;

	i = result;
	while (*i != NULL)
	{
		string = *i;
		free(string);
		i ++;
	}
	free(result);
}

int	main(int argc, char **argv)
{
	char	*arg;
	char	**result;

	if (argc != 2)
		return (1);
	arg = argv[1];
	printf("Splitting \"%s\" into multiple words...\n", arg);
	result = ft_split(arg);
	if (!result)
		return (1);
	ft_print_result(result);
	ft_free_result(result);
	return (0);
}
