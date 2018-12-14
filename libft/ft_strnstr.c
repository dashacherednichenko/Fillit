/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:57:36 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/02 11:17:18 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t ii;
	size_t lenstr;

	lenstr = ft_strlen(needle);
	i = 0;
	if (*needle == 0)
		return ((char*)&(haystack[i]));
	while (haystack[i] != '\0')
	{
		ii = 0;
		if (haystack[i] == needle[ii])
		{
			while (needle[ii] && haystack[i + ii] &&\
					haystack[i + ii] == needle[ii] && (i + ii) < len)
				ii++;
			if (ii == lenstr)
				return ((char*)&(haystack[i]));
			i = i + 1;
		}
		i++;
	}
	return (0);
}
