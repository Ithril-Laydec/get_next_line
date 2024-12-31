/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:34 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/31 13:30:12 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_buffer(char *buffer[MAX_FD], int fd)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[fd][i] && buffer[fd][i] != '\n')
		i++;
	if (!buffer[fd][i])
	{
		free(buffer[fd]);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer[fd]) - i + 1);
	i++;
	j = 0;
	while (buffer[fd][i])
		new_buffer[j++] = buffer[fd][i++];
	free(buffer[fd]);
	return (new_buffer);
}

char	*get_new_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_from_file(char *buffer[MAX_FD], int fd)
{
	char	*tmp;
	int		bytes_read;

	if (!buffer[fd])
		buffer[fd] = ft_calloc(1);
	tmp = ft_calloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			free(buffer[fd]);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer[fd]);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_from_file(buffer, fd);
	if (!buffer[fd])
		return (NULL);
	nl = get_new_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer, fd);
	return (nl);
}
