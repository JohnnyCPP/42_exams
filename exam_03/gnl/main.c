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
// printf() for debugging
#include <stdio.h>
// open() to open files
#include <fcntl.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*data_obtained;

	fd = open("./reading_files/file_nocontent.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: the file could not be opened.\n");
		return (0);
	}
	printf("INFO: file descriptor=%i\n\n", fd);
	data_obtained = get_next_line(fd);
	printf("INFO: data_obtained=\"%s\"\n", data_obtained);
	if (data_obtained)
		free(data_obtained);
	close(fd);
	return (0);
}
