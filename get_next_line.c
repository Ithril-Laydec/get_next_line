/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:34 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/29 17:54:00 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE];
	char		*nl;
	int			i;
	int			bytes_read;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	nl = NULL;
	bytes_read = 0;
	if (ft_strlen(buffer[fd]) > 0)
	{
		i = forward_i(buffer, fd, bytes_read);
		nl = create_new_line(buffer, fd, i);
		if (!nl)
			return (NULL);
		if (check_nl(nl, buffer, fd, i))
			return (nl);
	}
	while((bytes_read = read(fd, buffer[fd], BUFFER_SIZE)) > 0)
	{
		// printf("bytes_read: %d\n", bytes_read);
		i = forward_i(buffer,fd, bytes_read);
		if (!nl)
			nl = create_new_line(buffer, fd, i);
		else
			nl = join_new_line(nl, buffer, fd, i);
		if (!nl)
			return (NULL);
		if(check_nl(nl, buffer, fd, i) || bytes_read < BUFFER_SIZE)
			return (nl);
	}
	return (NULL);
}
