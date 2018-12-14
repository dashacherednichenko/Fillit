/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:44:56 by dpiven            #+#    #+#             */
/*   Updated: 2018/10/31 15:00:25 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ((unsigned char)c))
			return ((char *)&s[i]);
		if (s[i + 1] == ((unsigned char)c))
			return ((char *)&s[i + 1]);
		i++;
	}
	if (s[i] == '\0' && s[i] == ((unsigned char)c))
		return ((char *)&s[i]);
	return (0);
}
