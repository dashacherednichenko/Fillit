/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:55:30 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/26 17:31:52 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

t_lst	*ft_filllst(char ***tetr, int i, t_lst *tmp)
{
	int x;
	int y;
	int ix;
	int w;

	x = -1;
	ix = 0;
	while (++x < 4)
	{
		y = 0;
		if (ft_checkline(tetr[i][x]) == 0)
		{
			while (ft_checkcolumn(tetr[i], y) == 1)
				y++;
			tmp->str[ix] = ft_strduplastchr(&tetr[i][x][y], '.');
			w = ft_calcwidth(tmp->str[ix++]);
			(w > tmp->w) ? tmp->w = w : w;
		}
	}
	tmp->next = (t_lst*)malloc(sizeof(t_lst));
	tmp = tmp->next;
	return (tmp);
}
