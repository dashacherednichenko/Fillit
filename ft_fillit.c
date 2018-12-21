/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:12:00 by olrudenk          #+#    #+#             */
/*   Updated: 2018/12/21 19:12:08 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

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
		j = -1;
	}
	return (mtrx);
}

void	ft_plus(t_lst *tmp, int nb, int *i, int *j)
{
	if (tmp->crd[0].y < nb - 1)
	{
		if (tmp->str[0][0] == '.' && tmp->str[0][1] != '.')
			*j = tmp->crd[0].y;
		else if (tmp->str[0][0] == '.' && tmp->str[0][1] == '.')
			*j = tmp->crd[0].y - 1;
		else
			*j = tmp->crd[0].y + 1;
		*i = tmp->crd[0].x;
	}
	else if (tmp->crd[0].y == nb - 1 && tmp->crd[0].x < nb - 1)
	{
		*j = 0;
		*i = tmp->crd[0].x + 1;
	}
}
