/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:16:38 by dpiven            #+#    #+#             */
/*   Updated: 2018/10/30 13:18:45 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			len;
	size_t			n;
	size_t			tmp;
	unsigned int	i;

	i = 0;
	len = ft_strlen(dst);
	tmp = len;
	n = ft_strlen(src);
	if (dstsize < len)
		return (dstsize + n);
	if (dstsize > len)
	{
		while (src[i] != '\0' && tmp < (dstsize - 1))
		{
			dst[tmp] = src[i];
			tmp++;
			i++;
		}
		dst[tmp] = '\0';
	}
	return (len + n);
}
