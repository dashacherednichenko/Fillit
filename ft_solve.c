/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:12:47 by olrudenk          #+#    #+#             */
/*   Updated: 2018/12/23 16:34:48 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int		ft_checkfig(char **s, t_lst *lst, int i, int j)
{
	int	x;
	int	y;
	int	jj;
	int	nb;

	x = -1;
	while (++x < lst->h)
	{
		jj = j;
		y = 0;
		while (lst->str[x][y])
		{
			if ((i >= (nb = ft_strlen(*s)) || jj >= nb) || (i < nb && jj < nb
				&& s[i][jj] != '.' && lst->str[x][y] != '.'))
				return (lst->a == 'A' ? -1 : 0);
			if ((i < nb && jj < nb && s[i][jj] == '.'
				&& lst->str[x][y] != '.') || lst->str[x][y] == '.')
			{
				jj++;
				y++;
			}
		}
		i++;
	}
	return (1);
}

char	**ft_delfig(char **mtrx, t_lst *lst)
{
	int	z;

	z = -1;
	while (++z < 4)
		mtrx[lst->crd[z].x][lst->crd[z].y] = '.';
	return (mtrx);
}

t_lst	*ft_searchl(t_lst *list, char a)
{
	t_lst	*ptr;

	ptr = list;
	while (ptr)
		if (ptr->a == a)
			return (ptr);
		else
			ptr = ptr->next;
	return (0);
}

t_lst	*ft_locate(char **mtrx, t_lst *ptr, int i, int j)
{
	int	x;
	int	y;
	int	z;
	int	jj;

	x = -1;
	z = 0;
	while (++x < ptr->h && mtrx[i][j] && ptr->next)
	{
		y = -1;
		jj = j;
		while (ptr->str[x][++y] && mtrx[i][jj])
		{
			if (mtrx[i][jj] == '.' && ptr->str[x][y] != '.')
			{
				mtrx[i][jj] = ptr->str[x][y];
				ptr->crd[z].x = i;
				ptr->crd[z++].y = jj;
			}
			jj++;
		}
		i++;
	}
	return (ptr);
}

char	**ft_solve(char **mtrx, t_lst *lst, int nb, t_lst *ptr)
{
	static int	i = 0;
	static int	j = 0;
	int			z;
	t_lst		*tmp;

	(ptr->a > 'A') ? (tmp = ft_searchl(lst, ptr->a - 1)) : 0;
	while (i < nb)
	{
		while (mtrx[i][j] && ptr->next)
			if ((z = ft_checkfig(mtrx, ptr, i, j++)) == 1)
			{
				ptr = ft_locate(mtrx, ptr, i, j - 1);
				tmp = ptr;
				ptr = ptr->next;
				ft_nulij(&i, &j);
			}
		j = 0;
		i++;
	}
	(z == -1 && ptr->a == 'A') ? ft_nulij(&i, &j) : i;
	if (z == -1 && ptr->a == 'A' && nb++)
		return (mtrx = ft_solve(ft_createmtrx(nb), lst, nb, ptr));
	ptr->next ? ft_plus(tmp, nb, &i, &j) : 0;
	ptr->next ? (mtrx = ft_solve(ft_delfig(mtrx, tmp), lst, nb, tmp)) : 0;
	return (mtrx);
}
