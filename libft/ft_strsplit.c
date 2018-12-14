/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:24:33 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/05 19:03:09 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_mallocarr(char const *s, char c)
{
	int		i;
	int		x;
	char	**newarr;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			x++;
		}
	}
	newarr = (char**)malloc(sizeof(char*) * (x + 1));
	return (newarr);
}

static int		ft_sizestr(char const *s, char c, int i)
{
	int y;

	y = 0;
	while (s[i + y] != c && s[i + y])
		y++;
	return (y);
}

static char		**ft_newarr(char const *s, char c, char **newarr)
{
	int i;
	int y;
	int x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			y = 0;
			while (s[i] != c && s[i])
			{
				newarr[x][y++] = s[i];
				i++;
			}
			x++;
		}
	}
	newarr[x] = NULL;
	return (newarr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		x;
	char	**newarr;

	if (s == 0)
		return (0);
	newarr = ft_mallocarr(s, c);
	if (newarr == 0)
		return (0);
	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			newarr[x++] = ft_strnew(ft_sizestr(s, c, i));
			i = i + ft_sizestr(s, c, i);
		}
	}
	newarr = ft_newarr(s, c, newarr);
	return (newarr);
}
