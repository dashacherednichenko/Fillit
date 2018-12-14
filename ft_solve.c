/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:12:47 by olrudenk          #+#    #+#             */
/*   Updated: 2018/12/13 19:15:24 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

void	**ft_createmtrx(int nb, t_lst *lst)
{
    char	**mtrx;
    int		i;
	int		j;

    i = -1;
    j = -1;
    mtrx = (char**)malloc(sizeof(char*) * (nb + 1))
    mtrx[nb + 1] = 0;
    while (++i < nb)
    {
        mtrx[i] = (char*)malloc(sizeof(char) * (nb + 1))
        while (++j < nb)
			mtrx[i][j] = '.';
        mtrx[i][j + 1] = 0;
        j = -1;
    }
    ft_solve (mtrx, lst, nb);
}
