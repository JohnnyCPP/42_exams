/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:17:10 by jonnavar          #+#    #+#             */
/*   Updated: 2025/03/06 21:02:26 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./get_next_line.h"

char	*gnl_cut(const char *string, size_t start, size_t length)
{
	char	*result;
	size_t	index;
	size_t	string_length;

	if (!string)
		return (NULL);
	string_length = gnl_length(string);
	if (start > string_length)
		return (gnl_copy(""));
	if (start + length > string_length)
		length = string_length - start;
	result = (char *) malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (string[start + index] && index < length)
	{
		result[index] = string[start + index];
		index ++;
	}
	result[index] = '\0';
	return (result);
}

char	*gnl_copy(const char *string)
{
	char	*result;
	ssize_t	index;
	ssize_t	result_length;

	if (!string)
		return (NULL);
	result_length = gnl_length(string) + 1;
	result = (char *) malloc(sizeof(char) * result_length);
	if (!result)
		return (NULL);
	index = -1;
	while (++ index < result_length)
		result[index] = string[index];
	return (result);
}

char	*gnl_concat(const char *destination, const char *source)
{
	char		*result;
	size_t		result_length;
	ssize_t		source_length;
	ssize_t		dest_length;

	if (!destination || !source)
		return (NULL);
	result_length = gnl_length(destination) + gnl_length(source) + 1;
	result = (char *) malloc(sizeof(char) * result_length);
	if (!result)
		return (NULL);
	dest_length = -1;
	while (destination[++ dest_length])
		result[dest_length] = destination[dest_length];
	source_length = -1;
	while (source[++ source_length])
		result[dest_length + source_length] = source[source_length];
	result[dest_length + source_length] = '\0';
	return (result);
}

char	*gnl_contains(const char *string, char character)
{
	char	*aux_pointer;
	int		index;

	if (!string)
		return (NULL);
	aux_pointer = (char *) string;
	index = 0;
	while (aux_pointer[index])
	{
		if (aux_pointer[index] == character)
			return (aux_pointer + index);
		index ++;
	}
	return (NULL);
}

size_t	gnl_length(const char *string)
{
	size_t	index;

	if (!string)
		return (0);
	index = 0;
	while (string[index])
		index ++;
	return (index);
}

char	*gnl_check_nl(int next_line, char **file_address)
{
	char	*substring;
	char	*result;

	substring = NULL;
	if (next_line <= 0)
	{
		if (**file_address == '\0')
		{
			free(*file_address);
			*file_address = NULL;
			return (NULL);
		}
		result = *file_address;
		*file_address = NULL;
		return (result);
	}
	substring = gnl_cut(*file_address, next_line, BUFFER_SIZE);
	result = *file_address;
	result[next_line] = '\0';
	*file_address = substring;
	return (result);
}

void	gnl_free_address(char **pointer)
{
	if (*pointer)
	{
		free(*pointer);
		pointer = NULL;
	}
}

char	*gnl_read(int fd, char **file_address, char *reading_buffer)
{
	ssize_t	bytes_read;
	char	*saved_str;
	char	*next_line;

	bytes_read = 0;
	saved_str = NULL;
	next_line = gnl_contains(*file_address, '\n');
	while (!next_line)
	{
		bytes_read = read(fd, reading_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (gnl_check_nl(bytes_read, file_address));
		reading_buffer[bytes_read] = '\0';
		saved_str = gnl_concat(*file_address, reading_buffer);
		gnl_free_address(file_address);
		*file_address = saved_str;
		next_line = gnl_contains(*file_address, '\n');
	}
	return (gnl_check_nl(next_line - *file_address + 1, file_address));
}

char	*get_next_line(int fd)
{
	static char	*file_addresses[256];
	char		*reading_buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	reading_buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!reading_buffer)
		return (NULL);
	if (!file_addresses[fd])
		file_addresses[fd] = gnl_copy("");
	result = gnl_read(fd, &file_addresses[fd], reading_buffer);
	gnl_free_address(&reading_buffer);
	return (result);
}
