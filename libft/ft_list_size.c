/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:55:31 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/10 15:11:28 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_size(t_list *begin_list)
{
	size_t		len;
	t_list		*temp;

	if (!begin_list)
		return (0);
	len = 0;
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
