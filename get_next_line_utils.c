/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:20:19 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/28 19:13:57 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_front(t_fd_list **lst, t_fd_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_fd_list **lst, t_fd_list *new)
{
	t_fd_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

t_fd_list	*ft_lstnew(int fd)
{
	t_fd_list	*list;

	list = malloc(sizeof(t_fd_list));
	if (!list)
		return (NULL);
	list->remaining = NULL;
	list->fd = fd;
	list->next = NULL;
	return (list);
}

int	init_warehouse(t_warehouse **wh, int fd)
{
	if (*wh)
		return (1);
	*wh = malloc(sizeof(t_warehouse));
	if (!*wh)
		return (0);
	(*wh)->fd_list = ft_lstnew(fd);
	(*wh)->nl = NULL;
	(*wh)->i = 0;
	(*wh)->current = NULL;
	return (1);
}

t_fd_list	*search_fd(t_warehouse *wh, int fd)
{
	t_fd_list	*tmp;
	
	// printf("fd: %d\n", fd);
	if (init_warehouse(&wh, fd) == 0)
		return (NULL);
	tmp = wh->fd_list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(fd);
	if (!tmp)
		return (NULL);
	ft_lstadd_back(&wh->fd_list, tmp);
	return (tmp);
}
