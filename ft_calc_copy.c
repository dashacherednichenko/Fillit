/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:46:35 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/26 17:31:36 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		ft_calcheight(char **str, char a)
{
	int x;
	int h;

	x = 0;
	h = 0;
	while (x < 4)
	{
		if (ft_strchr(str[x], a))
			h++;
		x++;
	}
	return (h);
}

int		ft_calcwidth(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strduplastchr(const char *s1, char c)
{
	char	*s2;
	int		len;
	int		i;
	int		ii;

	ii = 0;
	while (s1[ii] == c)
		ii++;
	i = ii;
	while (s1[i] != c && s1[i])
		i++;
	len = i;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	ii = 0;
	while (i < len)
		s2[ii++] = s1[i++];
	s2[ii] = 0;
	return (s2);
}

int		ft_checkline(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] != '.')
			return (0);
	return (1);
}

int		ft_checkcolumn(char **str, int y)
{
	int x;

	x = 0;
	while (x < 4)
		if (str[x++][y] != '.')
			return (0);
	return (1);
}
