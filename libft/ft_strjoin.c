/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:26:03 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/22 14:33:29 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	size_t		i;
	size_t		ii;

	i = 0;
	ii = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (newstr == 0)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[ii])
	{
		newstr[i] = s2[ii];
		ii++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
