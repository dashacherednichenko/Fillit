/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:50:14 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/06 20:01:04 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*temp;
	int		i;

	if (!f || !lst)
		return ;
	i = 0;
	temp = lst;
	while (temp)
	{
		f(temp);
		temp = temp->next;
	}
}
