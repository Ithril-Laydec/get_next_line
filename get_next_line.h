/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:44 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/30 17:17:20 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# ifndef MAX_FD
#  define MAX_FD 19999
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		forward_i(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int bytes_read);
char	*create_new_line(char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i);
char	*join_new_line(char *nl,
			char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i);
int		check_nl(char *nl, char buffer[MAX_FD][BUFFER_SIZE + 1], int fd, int i);
char		*ft_strchr(const char *s, int c);

#endif
