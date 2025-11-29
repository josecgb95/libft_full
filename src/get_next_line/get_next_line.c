/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:25:27 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:03:43 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*read_fd_and_copy(int fd, char *storage)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(storage), NULL);
	while (!ft_strchr_gnl(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if ((storage && storage[0]) && bytes_read == 0)
				return (free(buffer), storage);
			return (free(buffer), free(storage), NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(storage, buffer);
		if (!temp)
			return (free(buffer), free(storage), NULL);
		storage = temp;
	}
	return (free(buffer), storage);
}

char	*extract_line(char *storage)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!storage || !storage[0])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_remainder(char *storage)
{
	char	*remainder;
	size_t	start;
	size_t	len;
	size_t	i;

	if (!storage)
		return (NULL);
	start = 0;
	while (storage[start] && storage[start] != '\n')
		start++;
	if (!storage[start])
		return (free(storage), NULL);
	start++;
	len = ft_strlen_gnl(storage + start);
	if (len == 0)
		return (free(storage), NULL);
	remainder = (char *)malloc(sizeof(char) * (len + 1));
	if (!remainder)
		return (free(storage), NULL);
	i = 0;
	while (storage[start])
		remainder[i++] = storage[start++];
	remainder[i] = '\0';
	return (free(storage), remainder);
}

char	*get_next_line(int fd)
{
	static char	*storage[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
	{
		storage[fd] = malloc(1);
		if (!storage[fd])
			return (NULL);
		storage[fd][0] = '\0';
	}
	storage[fd] = read_fd_and_copy(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	if (!line)
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	storage[fd] = save_remainder(storage[fd]);
	return (line);
}
