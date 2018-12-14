/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:52:03 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/02 20:23:08 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*newstr;
	size_t		i;

	i = 0;
	if (s == 0)
		return (0);
	newstr = ft_strnew(len);
	if (newstr == 0)
		return (0);
	while (i < len && s[start + i])
	{
		newstr[i] = s[start + i];
		i++;
	}
	return (newstr);
}
