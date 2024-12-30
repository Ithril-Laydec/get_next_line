/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:34 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/30 17:29:54 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dol(char *s)
{
	int i = 0;
	char *nl;
	nl = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		if (s[i] == '\n')
			nl[i] = '$';
		i++;
	}
	nl[i] = '\0';
	return (nl);
}
void	*ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (str);
}

char	*search_in_buffer(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd)
{
	int		i;
	char	*nl;
	int		len;

	i = ft_strchr(buffer[fd], '\n') - buffer[fd];
	nl = create_new_line(buffer, fd, i);
	if (nl)
	{
		printf("(buffer[fd]: %s)\n", dol(buffer[fd]));
		len = ft_strlen(nl);
		i = 0;
		while (i < BUFFER_SIZE + 1 - len)
		{
			buffer[fd][i] = buffer[fd][i + len];
			i++;
		}
		buffer[fd][len] = '\0';
		return (nl);
	}
	return (NULL);
}

int	there_is_nl(char *nl)
{
	int	i;

	i = 0;
	while (nl[i])
	{
		if (nl[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*search_in_file(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd)
{
	int		bytes_read;
	int		i;
	char	*nl;

	// printf("(search_in_file)\n");
	bytes_read = 0;
	if (ft_strlen(buffer[fd]) > 0)
		nl = search_in_buffer(buffer, fd);
	else
		nl = NULL;
	while ((bytes_read = read(fd, buffer[fd], BUFFER_SIZE)) > 0)
	{
	// printf("bytes_read: %d\n", bytes_read);
		buffer[fd][bytes_read] = '\0';
		// i = forward_i(buffer, fd, bytes_read);
		// printf("i: %d\n", i);
		i = ft_strchr(buffer[fd], '\n') - buffer[fd];
		printf("i: %d\n", i);
		if (!nl)
			nl = create_new_line(buffer, fd, i);
		else
			nl = join_new_line(nl, buffer, fd, i);
		if (!nl)
			return (NULL);
		if (there_is_nl(nl))
			break ;
	}
	if (bytes_read == 0)
	{
		ft_bzero(buffer[fd], BUFFER_SIZE + 1);
		return (nl);
	}
	if (check_nl(nl, buffer, fd, i))
		return (nl);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*nl;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE + 1 <= 0)
		return (NULL);
	nl = NULL;
	if (ft_strlen(buffer[fd]) > 0)
		nl = search_in_buffer(buffer, fd);
	else
		nl = search_in_file(buffer, fd);
	if (!nl)
		return (NULL);
	return (nl);
}
