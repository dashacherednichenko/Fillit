/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:22:09 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/10 17:02:33 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsplit(char const *s, char c)
{
	t_list	*begin;
	char	**newarr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	newarr = ft_strsplit(s, c);
	begin = NULL;
	ft_lstadd(&begin, ft_lstnew(newarr[i], ft_strlen(newarr[i])));
	i++;
	while (newarr[i])
	{
		ft_lstaddend(&begin, ft_lstnew(newarr[i], ft_strlen(newarr[i])));
		i++;
	}
	return (begin);
}
