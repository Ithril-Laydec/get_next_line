/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:34 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/28 19:18:07 by itjimene         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strndup(const char *s, int n)
{
	char	*new_str;
	int		i;

	// printf("(strndup)\n");
	// printf("n: %d\n", n);
	// printf("s: %zu\n", ft_strlen(s));
	new_str = (char *)malloc(sizeof(char) * (n + 1));
	// printf("post malloc\n");
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[n] = '\0';
	return (new_str);
}

char	*ft_strnjoin(t_warehouse *wh)
{
	char	*new_str;
	int		old_len;
	int		i;

	// printf("(strnjoin)\n");
	if (!wh->nl)
		return (ft_strndup(wh->buffer, wh->i));
	old_len = 0;
	while(wh->nl[old_len])
		old_len++;
	// printf("old_len: %d\n", old_len);
	new_str = malloc(sizeof(char) * (old_len + wh->i + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < old_len)
	{
		new_str[i] = wh->nl[i];
		i++;
	}
	i = 0;
	while (i < wh->i)
	{
		new_str[old_len + i] = wh->buffer[i];
		i++;
	}
	new_str[old_len + i] = '\0';
	free(wh->nl);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static t_warehouse	*wh;

	// if(!wh)
	// 	init_warehouse(wh);
	// printf("(gnl)\n");
	if(fd < 0 || BUFFER_SIZE <= 0 || !search_fd(wh, fd))
		return (NULL);
	int read_bytes = read(fd, wh->buffer, BUFFER_SIZE);
	wh->buffer[read_bytes] = '\0';
	printf("buffer: %s\n", wh->buffer);
	printf("(gnl)\n");
	while(read(fd, wh->buffer, BUFFER_SIZE) > 0)
	{
		wh->i = 0;
		while(wh->buffer[wh->i] != '\n' && wh->i < BUFFER_SIZE)
			wh->i++;
		wh->nl = ft_strnjoin(wh);
		// printf("nl: %s\n", wh->nl);
		if (wh->nl == NULL)
			return (NULL);
		if (wh->buffer[wh->i] == '\n')
			break;
	}
	if (wh->i < BUFFER_SIZE)
	{
		if (wh->current->remaining)
			free(wh->current->remaining);
		wh->current->remaining = ft_strndup(&wh->buffer[wh->i + 1], BUFFER_SIZE - wh->i -1);
		// printf("(gnl)\n");
	}
	if (wh->nl)
		return (wh->nl);
	return (NULL);
}