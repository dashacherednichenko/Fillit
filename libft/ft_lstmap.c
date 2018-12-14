/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:02:53 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/10 09:44:19 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *newlst;
	t_list *begin;

	if (!f || !lst)
		return (NULL);
	temp = f(lst);
	if (!(newlst = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	begin = newlst;
	while (lst->next)
	{
		temp = f(lst->next);
		if (!(newlst->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (begin);
}
