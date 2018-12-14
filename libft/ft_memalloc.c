/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:52:49 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/02 16:23:02 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	if (size == 0)
		return (0);
	s = (void*)malloc(sizeof(void) * size);
	if (s == 0)
		return (0);
	ft_bzero(s, size);
	return (s);
}
