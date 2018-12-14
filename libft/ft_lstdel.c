/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:50:53 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/10 08:54:19 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!alst || !*alst || !*del)
		return ;
	temp = *alst;
	while (temp)
	{
		del(temp->content, temp->content_size);
		free((void**)temp);
		temp = temp->next;
	}
	*alst = NULL;
}
