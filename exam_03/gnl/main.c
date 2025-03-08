/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:17:10 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 21:05:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printf()
#include <stdio.h>
// open()
#include <fcntl.h>
// close()
#include <unistd.h>
// free()
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(int argc, char **argv)
{
	int		fd;
	char	*next_line;

	if (argc != 2)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: file could not be opened.\n");
		return (EXIT_FAILURE);
	}
	printf("INFO: file descriptor=%i\n\n", fd);
	next_line = get_next_line(fd);
	printf("INFO: data in file=\n");
	while (next_line)
	{
		printf("%s", next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	if (next_line)
		free(next_line);
	close(fd);
	return (EXIT_SUCCESS);
}
