/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:43:13 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/05 15:02:27 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*newstr;
	size_t	i;
	size_t	ii;
	size_t	len;

	i = 0;
	ii = 0;
	if (s == 0)
		return (0);
	len = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (i < len)
		while ((s[len - 1] == ' ' || s[len - 1] == '\n' ||\
				s[len - 1] == '\t') && len)
			len--;
	newstr = ft_strnew(len - i);
	if (newstr == 0)
		return (0);
	while (i < len)
	{
		newstr[ii++] = s[i];
		i++;
	}
	return (newstr);
}
