/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:12:47 by olrudenk          #+#    #+#             */
/*   Updated: 2018/12/19 19:55:57 by dpiven           ###   ########.fr       */
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
//			else if (lst->str[x][y] == '.')
//			{
//				y++;
//			}
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
//		printf("%d-",lst->crd[z].x);
//		printf("%d\n",lst->crd[z].y);
		z++;
	}
	return (mtrx);
}

t_lst	*ft_searchl(t_lst *list, char a)
{
	t_lst *ptr;

	ptr = list;
	while (ptr)
	{
		if (ptr->a == a)
			return (ptr);
		else
			ptr = ptr->next;
	}
	return (0);
}


t_lst	*ft_locate(char **mtrx, t_lst *ptr, int i, int j)
{
	int x;
	int y;
	int z;
	int jj;

	x = 0;
	z = 0;
	while (x < ptr->h && mtrx[i][j] && ptr->next)
	{
		y = 0;
		jj = j;
		while(ptr->str[x][y] && mtrx[i][jj])
		{
			if (mtrx[i][jj] == '.' && ptr->str[x][y] != '.')
			{
				mtrx[i][jj] = ptr->str[x][y];
				ptr->crd[z].x = i;
				ptr->crd[z++].y = jj;
//				y++;
//				jj++;
			}
//			if (mtrx[i][jj] == '.' && ptr->str[x][y] == '.')
//			{
//				y++;
//			}
			y++;
			jj++;
		}
		x++;
		i++;
	}
	return (ptr);
}

char	**ft_solve(char **mtrx, t_lst *lst, int nb, int i, int j, t_lst *ptr)
{
	t_lst	*tmp;
	int z;
	int t;

	z = 0;
	if (!ptr)
		ptr = lst;
	if (ptr->a > 'A')
		tmp = ft_searchl(lst, ptr->a - 1);
	while (i < nb)
	{
		while (mtrx[i][j] && ptr->next)
		{
//			if (mtrx[i][j] == '.' && ft_checkfig(mtrx, ptr, i, j, nb) == 1)
			if ((z = ft_checkfig(mtrx, ptr, i, j, nb)) == 1)
			{
//				printf("\n%d %d %c\n", i, j, ptr->a); 
				ptr = ft_locate(mtrx, ptr, i, j);
				t = 0;
//				while (t < nb)
//					ft_putendl(mtrx[t++]);
				tmp = ptr;
				//			tmp = ptr->next;
				ptr = ptr->next;
//	printf("LOC-%c\n", ptr->a);
				i = 0;
				j = -1;
			}
//			else if (mtrx[i][j] == '.' && ft_checkfig(mtrx, ptr, i, j, nb) == -1 && ptr->a == 'A')
//			{
//				printf("%d - %d\n", i, j);
//				nb++;
//				mtrx = ft_createmtrx(nb);
//				mtrx = ft_solve(mtrx, lst, nb, 0, 0, ptr);
//				return (mtrx);
//			}
			j++;
		}
		j = 0;
		i++;
	}
	if (z == -1 && ptr->a == 'A')
	{
//              printf("%d - %d\n", i, j);
		nb++;
		mtrx = ft_createmtrx(nb);
		mtrx = ft_solve(mtrx, lst, nb, 0, 0, ptr);
		return (mtrx);
	}
//	i = 0;
	if (ptr->next)
	{
//		printf("#####%d\n", tmp->crd[0].y);
		mtrx = ft_delfig(mtrx, tmp);
		if (tmp->crd[0].y < nb - 1)
		{

//			printf("??%c\n", tmp->str[0][0]);
			if (tmp->str[0][0] == '.' && tmp->str[0][1] != '.')
			{
				j = tmp->crd[0].y;
//				printf("!!!!!!!!!!!!!!!!!!!!!!%d\n", tmp->crd[0].y);
			}
			else if (tmp->str[0][0] == '.' && tmp->str[0][1] == '.')
            {
                j = tmp->crd[0].y - 1;
//              printf("!!!!!!!!!!!!!!!!!!!!!!%d\n", tmp->crd[0].y);
            }
			else
				j = tmp->crd[0].y + 1;
			i = tmp->crd[0].x;
		}
		else if (tmp->crd[0].y == nb - 1 && tmp->crd[0].x < nb - 1)
		{
			j = 0;
//			if (tmp->str[0][0] == '.')
//				i = tmp->crd[0].x;
			//           else
				i = tmp->crd[0].x + 1;
		}
//		printf("%d %d %c\n", i, j, tmp->a);
		mtrx = ft_solve(mtrx, lst, nb, i, j, tmp);  
	}
	return (mtrx);
}
