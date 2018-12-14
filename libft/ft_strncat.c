/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:32:43 by dpiven            #+#    #+#             */
/*   Updated: 2018/10/30 11:35:31 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int len;
	unsigned int i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0' && i < n)
	{
		s1[len++] = s2[i];
		i++;
	}
	s1[len] = '\0';
	return (s1);
}
