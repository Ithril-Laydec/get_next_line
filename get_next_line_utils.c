/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:19 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/30 17:23:33 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s || (char)c == 0)
		return ((char *)s);
	return (NULL);
}
int	forward_i(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int bytes_read)
{
	int	i;

	i = 0;
	while ((buffer[fd][i] != '\n' || buffer[fd][i] == '\0')
			&& i < BUFFER_SIZE + 1 && i < bytes_read)
		i++;
	// if (buffer[fd][i] == '\n')
	// 	i++;
	return (i);
}

char	*create_new_line(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i)
{
	char	*nl;
	int		j;

	// if (i == 0)
	// 	return (NULL);
	j = 0;
	nl = malloc(sizeof(char) * (i + 1));
	if (!nl)
		return (NULL);
	while (j < i + 1)
	{
		nl[j] = buffer[fd][j];
		j++;
	}
	nl[j] = '\0';
	// printf("nl: %s|", nl);
	if (nl[ft_strlen(nl) - 1] == '\n')
	{
		j = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buffer[fd][j] = buffer[fd][i];
			i++;
			j++;
		}
		buffer[fd][j] = '\0';
	}
	return (nl);
}

char	*join_new_line(char *nl,
	char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i)
{
	char	*tmp;
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(nl);
	tmp = malloc(sizeof(char) * (i + len + 1));
	if (!tmp)
	{
		free(nl);
		return (NULL);
	}
	while (j < len)
	{
		tmp[j] = nl[j];
		j++;
	}
	j = 0;
	while (j < i)
	{
		tmp[len + j] = buffer[fd][j];
		j++;
	}
	tmp[len + j] = '\0';
	free(nl);
	nl = tmp;
	return (nl);
}

int	check_nl(char *nl, char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i)
{
	int		j;
	size_t	len;

	j = 0;
	if (!nl)
		return (0);
	len = ft_strlen(nl);
	if (len == 0)
		return (0);
	if (nl[len - 1] == '\n')
	{
		j = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buffer[fd][j] = buffer[fd][i];
			i++;
			j++;
		}
		buffer[fd][j] = '\0';
		return (1);
	}
	return (0);
}
