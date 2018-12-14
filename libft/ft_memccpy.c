/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:33:09 by dpiven            #+#    #+#             */
/*   Updated: 2018/10/30 19:29:14 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*mydst;
	unsigned char		*mysrc;
	unsigned char		*ptr;

	mydst = (unsigned char *)dst;
	mysrc = (unsigned char *)src;
	i = 0;
	ptr = 0;
	while ((n--) && ptr == 0)
	{
		mydst[i] = mysrc[i];
		if (mysrc[i] == ((unsigned char)c))
			ptr = &mydst[i + 1];
		i++;
	}
	return (ptr);
}
