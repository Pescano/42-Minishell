/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:44:37 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:44:43 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_fd(int fd, char *buffer_read)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer_read, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(buffer_read);
			return (NULL);
		}
		buffer[bytes] = '\0';
		buffer_read = ft_strjoin(buffer_read, buffer);
	}
	free(buffer);
	return (buffer_read);
}

char	*ft_get_line(char *buffer_read)
{
	size_t	x;

	x = 0;
	if (!buffer_read[x])
		return (NULL);
	while (buffer_read[x] != '\n' && buffer_read[x])
		x++;
	return (ft_strndup(buffer_read, x + 1));
}

char	*ft_restart(char *buffer_read)
{
	char	*new_buffer;
	size_t	x;
	size_t	new_len;

	x = 0;
	while (buffer_read[x] != '\n' && buffer_read[x])
		x++;
	if (!buffer_read[x])
	{
		free(buffer_read);
		return (NULL);
	}
	x++;
	new_len = ft_strlen(buffer_read) - x;
	new_buffer = ft_strndup(buffer_read + x, new_len);
	free(buffer_read);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_read = ft_read_fd(fd, buffer_read);
	if (!buffer_read)
		return (NULL);
	line = ft_get_line(buffer_read);
	buffer_read = ft_restart(buffer_read);
	return (line);
}
