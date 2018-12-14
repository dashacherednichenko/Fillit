/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:59:03 by dpiven            #+#    #+#             */
/*   Updated: 2018/10/31 18:25:29 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t ii;
	size_t len;

	len = ft_strlen(needle);
	i = 0;
	if (*needle == 0)
		return ((char*)&(haystack[i]));
	while (haystack[i] != '\0')
	{
		ii = 0;
		if (haystack[i] == needle[ii])
		{
			while (needle[ii] && haystack[i] && haystack[i] == needle[ii])
			{
				i++;
				ii++;
			}
			if (ii == len)
				return ((char*)&(haystack[i - ii]));
			i = i - ii + 1;
		}
		i++;
	}
	return (0);
}
