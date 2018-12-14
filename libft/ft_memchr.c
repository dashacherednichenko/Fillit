/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:23:27 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/10 14:43:53 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	int				i;
	unsigned char	*mys;

	ptr = 0;
	i = 0;
	mys = (unsigned char *)s;
	while (n-- && ptr == 0)
	{
		if (mys[i] == (unsigned char)c)
			ptr = &mys[i];
		i++;
	}
	return (ptr);
}
