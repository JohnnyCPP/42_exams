/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:59:24 by jonnavar          #+#    #+#             */
/*   Updated: 2024/11/01 16:01:42 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	printf()
#include <stdio.h>
//	atoi
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*no_1;
	char	*no_2;
	char	*operator;

	if (argc == 4)
	{
		no_1 = argv[1];
		no_2 = argv[3];
		operator = argv[2];
		if (*operator == '+')
			printf("%d", atoi(no_1) + atoi(no_2));
		if (*operator == '-')
			printf("%d", atoi(no_1) - atoi(no_2));
		if (*operator == '*')
			printf("%d", atoi(no_1) * atoi(no_2));
		if (*operator == '/')
			printf("%d", atoi(no_1) / atoi(no_2));
		if (*operator == '%')
			printf("%d", atoi(no_1) % atoi(no_2));
		printf("\n");
	}
	return (0);
}
