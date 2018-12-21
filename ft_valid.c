/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:30:10 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/17 13:52:47 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char	*ft_changehesh(char *line, int x)
{
	int i;

	i = -1;
	while (line[++i])
		line[i] == '#' ? (line[i] = 'A' + x) : i;
	return (line);
}

int		ft_cnct(char **str, char c)
{
	int x;
	int y;
	int i;

	x = -1;
	i = 0;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (str[x][y] == c)
			{
				((y + 1) < 4 && str[x][y + 1] == c) ? i++ : i;
				((x + 1) < 4 && str[x + 1][y] == c) ? i++ : i;
				((y - 1) >= 0 && str[x][y - 1] == c) ? i++ : i;
				((x - 1) >= 0 && str[x - 1][y] == c) ? i++ : i;
			}
	}
	return ((i == 6 || i == 8) ? 1 : 0);
}

int		ft_minsquare(int nb)
{
	int n;

	n = nb * 4;
	while (!ft_sqrt(n))
		n++;
	return (ft_sqrt(n));
}

char	***ft_malloc_tetr(void)
{
	char	***tetr;
	int		x;

	x = -1;
	tetr = (char***)malloc(sizeof(char**) * 26);
	while (++x < 26)
		tetr[x] = (char**)malloc(sizeof(char*) * 4);
	return (tetr);
}

void	ft_printmtrx(char **mtrx)
{
	int i;

	i = 0;
	while (mtrx[i])
		ft_putendl(mtrx[i++]);
}
