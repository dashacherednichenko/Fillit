/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:12:47 by olrudenk          #+#    #+#             */
/*   Updated: 2018/12/17 19:43:49 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#include <stdio.h>

char	**ft_createmtrx(int nb)
{
	char	**mtrx;
	int		i;
	int		j;

	i = -1;
	j = -1;
	mtrx = (char**)malloc(sizeof(char*) * (nb + 1));
	mtrx[nb + 1] = 0;
	while (++i < nb)
	{
		mtrx[i] = (char*)malloc(sizeof(char) * (nb + 1));
		while (++j < nb)
			mtrx[i][j] = '.';
		mtrx[i][j + 1] = 0;
//		ft_putendl(mtrx[i]);
		j = -1;
	}
	return (mtrx);
}

int ft_checkfig(char **s, t_lst *lst, int i, int j, int nb)
{
	int x;
	int y;
	int jj;

	x = -1;
	while (++x < lst->h)
	{
		jj = j;
		y = 0;
		while (lst->str[x][y])
		{
			if ((i >= nb || jj >= nb) || (i < nb && jj < nb && s[i][jj] != '.' && lst->str[x][y] != '.'))
				return (lst->a == 'A' ? -1 : 0);
			if ((i < nb && jj < nb && s[i][jj] == '.' && lst->str[x][y] != '.') || lst->str[x][y] == '.')
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
	int z;

	z = 0;
	while (z < 4)
	{
		mtrx[lst->crd[z].x][lst->crd[z].y] = '.';
		printf("%d-",lst->crd[z].x);
		printf("%d\n",lst->crd[z].y);
		z++;
	}
	return (mtrx);
}

char	**ft_solve(char **mtrx, t_lst *lst, int nb)
{
	int i;
	int j;
	int x;
	int y;
	t_lst *ptr;
	int jj;
	int ii;
	int z;
	t_lst *tmp;

	i = 0;
	ptr = lst;
	tmp = ptr;
	while (i < nb)
	{
		j = 0;
		while (mtrx[i][j] && ptr->next)
		{
			z = 0;
			if (mtrx[i][j] == '.' && ft_checkfig(mtrx, ptr, i, j, nb) == 1 && ptr->next)
			{
				x = 0;
				while (x < ptr->h && mtrx[i][j] && ptr->next)
				{
					y = 0;
					jj = j;
					while(ptr->str[x][y] && mtrx[i][jj] && ptr->next)
					{
						if (mtrx[i][jj] == '.' && ptr->str[x][y] != '.')
						{
							mtrx[i][jj] = ptr->str[x][y];
							ptr->crd[z].x = i;
							ptr->crd[z++].y = jj;
						}
						y++;
						jj++;
					}
					x++;
					i++;
				}
				printf("%d-", ptr->crd[0].x);
				printf("%d\n", ptr->crd[0].y);
				printf("%d-", ptr->crd[1].x);
                printf("%d\n", ptr->crd[1].y);
				printf("%d-", ptr->crd[2].x);
                printf("%d\n", ptr->crd[2].y);
				printf("%d-", ptr->crd[3].x);
				printf("%d\n", ptr->crd[3].y);
				tmp = ptr;
				ptr = ptr->next;
				i = 0;
				j = -1;
			}
			else if (i == 0 && j == 0 && mtrx[i][j] == '.' && ft_checkfig(mtrx, ptr, i, j, nb) == -1 && ptr->a \
                == 'A')
			{
				nb++;
				mtrx = ft_createmtrx(nb);
				mtrx = ft_solve(mtrx, ptr, nb);
				return (mtrx);
				ii = 0;
				tmp = ptr;
				ptr = ptr->next;
			}
			j++;
		}
//		ft_putendl(mtrx[i]);
		i++;
	}
	if (ptr->next)
	{
		printf("%c\n", tmp->a);
		mtrx = ft_delfig(mtrx, tmp);
	}
	return (mtrx);
}
