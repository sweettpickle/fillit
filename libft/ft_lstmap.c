/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:09:37 by cdoreah           #+#    #+#             */
/*   Updated: 2019/11/06 19:13:03 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	list_del(void *content, size_t content_size)
{
	if (content_size)
		free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*last;
	t_list	*head;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	last = NULL;
	while (lst)
	{
		if (!(cur = f(lst)))
		{
			ft_lstdel(&head, list_del);
			return (NULL);
		}
		if (last)
			last->next = cur;
		else
			head = cur;
		last = cur;
		lst = lst->next;
	}
	return (head);
}
