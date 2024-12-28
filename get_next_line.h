/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:44 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/28 19:34:14 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 87
# endif
# ifndef MAX_FD
#  define MAX_FD 19999
# endif

typedef struct	s_fd_list
{
	char				*remaining;
	struct s_fd_list	*next;
	int					fd;
}				t_fd_list;

typedef struct	s_warehouse
{
	t_fd_list		*fd_list;
	char			buffer[BUFFER_SIZE + 1];
	int				i;
	char			*nl;
	t_fd_list		*current;
}				t_warehouse;

char		*get_next_line(int fd);
char		*ft_strndup(const char *s, int n);
char		*ft_strnjoin(t_warehouse *wh);
t_fd_list	*search_fd(t_warehouse *wh, int fd);
size_t		ft_strlen(const char *str);
// void		*ft_realloc(void *ptr, size_t size);
t_fd_list	*ft_lstnew(int fd);
void		ft_lstadd_front(t_fd_list **lst, t_fd_list *new);
void		ft_lstadd_back(t_fd_list **lst, t_fd_list *new);




# endif
