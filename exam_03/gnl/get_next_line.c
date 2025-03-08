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

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

/**
 * @note This file won't comply norminette, but exam 03 doesn't require it
 */

/**
 * @brief Gets the length of a string until '\0' (excluded).
 */
size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i ++;
	return (i);
}

/**
 * @brief Copies a string, including the null character '\0'.
 *
 * @return A copy of "str", dynamically allocated.
 */
char	*gnl_strcpy(const char *str)
{
	char	*copy;
	size_t	length;
	size_t	i;

	if (!str)
		return (NULL);
	length = gnl_strlen(str);
	copy = (char *) malloc(sizeof(char) * length + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < length + 1)
	{
		copy[i] = str[i];
		i ++;
	}
	return (copy);
}

/**
 * @brief Gets a dynamically allocated piece of a string.
 *
 * @param str Target string.
 * @param start First character of the segment.
 * @param end Amount of characters included in the segment.
 *
 * @return A null-terminated string, starting on "start".
 *         Includes "end" characters, and a null-terminator '\0'.
 *
 * If the combination of "start" and "end" exceeds "str" length, 
 * it adjusts "end" to avoid reading out of bounds.
 */
char	*gnl_cut(const char *str, size_t start, size_t end)
{
	char	*cut;
	size_t	i;
	size_t	strlen;

	if (!str)
		return (NULL);
	strlen = gnl_strlen(str);
	if (start > strlen)
		return (gnl_strcpy(""));
	if (start + end > strlen)
		end = strlen - start;
	cut = (char *) malloc(sizeof(char) * end + 1);
	if (!cut)
		return (NULL);
	i = 0;
	while (str[start + i] && i < end)
	{
		cut[i] = str[start + i];
		i ++;
	}
	cut[i] = '\0';
	return (cut);
}

/**
 * @brief Joins two strings together, and returns a pointer to the result.
 * 
 * The returned string is null-terminated and dynamically allocated.
 */
char	*gnl_concat(const char *dest, const char *src)
{
	char		*concat;
	size_t		len_concat;
	size_t		len_dest;
	size_t		len_src;

	if (!dest || !src)
		return (NULL);
	len_concat = gnl_strlen(dest) + gnl_strlen(src);
	concat = (char *) malloc(sizeof(char) * len_concat + 1);
	if (!concat)
		return (NULL);
	len_dest = 0;
	while (dest[len_dest])
	{
		concat[len_dest] = dest[len_dest];
		len_dest ++;
	}
	len_src = 0;
	while (src[len_src])
	{
		concat[len_dest + len_src] = src[len_src];
		len_src ++;
	}
	concat[len_dest + len_src] = '\0';
	return (concat);
}

/**
 * @brief Gets the position of character "c" in string "str".
 */
char	*gnl_get_pos(const char *str, char c)
{
	char	*aux;
	size_t	i;

	if (!str)
		return (NULL);
	aux = (char *) str;
	i = 0;
	while (aux[i])
	{
		if (aux[i] == c)
			return (&aux[i]);
		i ++;
	}
	return (NULL);
}

/**
 * @brief Breaks a string, at 'i' index, in two parts.
 *
 * @param str A double pointer to the string to break.
 * @param i Position where the string is willing to be broken.
 *
 * @return The string pointed to by "str", null-terminated on 'i' index.
 */
char	*gnl_break_str(char **str, int i)
{
	char	*cut;
	char	*aux;

	cut = gnl_cut(*str, i, gnl_strlen(*str) - i);
	aux = *str;
	aux[i] = '\0';
	*str = cut;
	return (aux);
}

/**
 * @brief Handles the case when end of file is reached.
 *
 * @param str Address of the static buffer that stores the accumulated 
 *            data read from the file descriptor so far.
 * @param read_buf Buffer used for "read()" calls.
 *
 * - If the string pointed to by "str" is empty: 
 *   frees "*str", assigns it to NULL, and returns NULL.
 * - If the string pointed to by "str" is not empty: 
 *   assigns NULL to "*str", and returns the original value of "*str" 
 *   (this effectively returns the complete "*str", moving it from "str").
 * 
 * This function will free "read_buf" memory.
 */
char	*gnl_handle_eof(char **str, char *read_buf)
{
	char	*aux;

	if (read_buf)
		free(read_buf);
	if (**str == '\0')
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	aux = *str;
	*str = NULL;
	return (aux);
}

/**
 * @brief Frees the memory pointed to by "buffer" and returns NULL.
 *
 * This function assigns "*buffer" to NULL.
 */
char	*gnl_free_buffer(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

/**
 * @brief Reads from "fd" until a new line is found, or EOF is reached.
 *
 * @param fd The file descriptor pointing to the file to read from.
 * @param buffer Address of the static buffer that stores the accumulated 
 *               data read from the file descriptor so far.
 *
 * @return The (null-terminated) string read from "fd", including 
 *         a '\n' character if present.
 *         If EOF is reached or "read()" is unable to read from "fd", 
 *         returns NULL.
 *
 * "buffer" address points to a static buffer that is meant to accumulate 
 * the reading process after a new line character, if EOF is not reached yet.
 *
 * When this function reaches EOF, returns the progress read from "fd", 
 * and sets the address pointed to by "buffer" to NULL.
 */
char	*gnl_read(int fd, char **buffer)
{
	ssize_t	bytes;
	char	*read_buf;
	char	*concat;
	char	*new_line;

	bytes = 0;
	read_buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buf)
		return (gnl_free_buffer(buffer));
	new_line = gnl_get_pos(*buffer, '\n');
	while (!new_line)
	{
		bytes = read(fd, read_buf, BUFFER_SIZE);
		if (bytes <= 0)
			return (gnl_handle_eof(buffer, read_buf));
		read_buf[bytes] = '\0';
		concat = gnl_concat(*buffer, read_buf);
		if (buffer && *buffer)
			free(*buffer);
		*buffer = concat;
		new_line = gnl_get_pos(*buffer, '\n');
	}
	if (read_buf)
		free(read_buf);
	return (gnl_break_str(buffer, new_line - *buffer + 1));
}

/**
 * @brief Gets a line read from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * 
 * @return A pointer to the (dynamically allocated) string read.
 *         In case of error, returns NULL.
 *         The returned string is null-terminated ('\0').
 *
 *
 * The line read is defined as a succession of 0 to 'n' characters 
 * that end with '\n' or with the end of file (EOF).
 * Note: "read()" returns 0 if the EOF is reached.
 *
 * The line returned includes the '\n' character in case there is one.
 *
 * The program including this function will be compiled modifying 
 * BUFFER_SIZE with the flag "-D BUFFER_SIZE=xx".
 *
 * Calling this function in a loop, allows to read an entire file 
 * (static char *).
 *
 * Calling this function with different file descriptors allows to 
 * read them simultaneously in the same program without losing 
 * reading progress (*buffers[1024], where 1024 is the maximum amount 
 * of different file descriptors allowed in a given program).
 *
 * Note: value "1024" is chosen because it's usually the soft cap of 
 * file descriptors for a process in Linux. So, this program supports 
 * up to that amount, but if it's run in an OS that doesn't allow 
 * this amount of file descriptors, "open()" will not provide 
 * a proper file descriptor to the caller. 
 * This case is out of scope of this function. If an unproper file descriptor 
 * is provided, it will be considered as an error (and return NULL).
 */
char	*get_next_line(int fd)
{
	static char	*buffers[1024];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (!buffers[fd])
		buffers[fd] = gnl_strcpy("");
	next_line = gnl_read(fd, &buffers[fd]);
	return (next_line);
}
