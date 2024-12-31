/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:19 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/31 12:29:02 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;
	char	*tmp;
	size_t	i;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	tmp = (char *)ptr;
	i = 0;
	while (i < total_size)
	{
		tmp[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

// int	forward_i(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int bytes_read)
// {
// 	int	i;

// 	i = 0;
// 	while ((buffer[fd][i] != '\n' || buffer[fd][i] == '\0')
// 			&& i < BUFFER_SIZE + 1 && i < bytes_read)
// 		i++;
// 	// if (buffer[fd][i] == '\n')
// 	// 	i++;
// 	return (i);
// }

// char	*create_new_line(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i)
// {
// 	char	*nl;
// 	int		j;

// 	// if (i == 0)
// 	// 	return (NULL);
// 	j = 0;
// 	nl = malloc(sizeof(char) * (i + 1));
// 	if (!nl)
// 		return (NULL);
// 	while (j < i + 1)
// 	{
// 		nl[j] = buffer[fd][j];
// 		j++;
// 	}
// 	nl[j] = '\0';
// 	// printf("nl: %s|", nl);
// 	if (nl[ft_strlen(nl) - 1] == '\n')
// 	{
// 		j = 0;
// 		while (i < BUFFER_SIZE + 1)
// 		{
// 			buffer[fd][j] = buffer[fd][i];
// 			i++;
// 			j++;
// 		}
// 		buffer[fd][j] = '\0';
// 	}
// 	return (nl);
// }

// char	*join_new_line(char *nl,
// 	char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i)
// {
// 	char	*tmp;
// 	int		len;
// 	int		j;

// 	j = 0;
// 	len = ft_strlen(nl);
// 	tmp = malloc(sizeof(char) * (i + len + 1));
// 	if (!tmp)
// 	{
// 		free(nl);
// 		return (NULL);
// 	}
// 	while (j < len)
// 	{
// 		tmp[j] = nl[j];
// 		j++;
// 	}
// 	j = 0;
// 	while (j < i)
// 	{
// 		tmp[len + j] = buffer[fd][j];
// 		j++;
// 	}
// 	tmp[len + j] = '\0';
// 	free(nl);
// 	nl = tmp;
// 	return (nl);
// }

// int	check_nl(char *nl, char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i)
// {
// 	int		j;
// 	size_t	len;

// 	j = 0;
// 	if (!nl)
// 		return (0);
// 	len = ft_strlen(nl);
// 	if (len == 0)
// 		return (0);
// 	if (nl[len - 1] == '\n')
// 	{
// 		j = 0;
// 		while (i < BUFFER_SIZE + 1)
// 		{
// 			buffer[fd][j] = buffer[fd][i];
// 			i++;
// 			j++;
// 		}
// 		buffer[fd][j] = '\0';
// 		return (1);
// 	}
// 	return (0);
// }
