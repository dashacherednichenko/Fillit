/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:35:54 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/17 18:49:55 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"

char	*g_line;
int		g_x;
int		g_y;
int		g_z;

int		ft_jumptetr(int fd, char **str)
{
	if (g_z != 4 || !(ft_cnct(str, 'A' + g_x)))
		return (0);
	g_x++;
	g_y = 0;
	g_z = 0;
	free(g_line);
	get_next_line(fd, &g_line);
	return (1);
}

char	***arrdel(char ***str)
{
	int x;
	int y;

	x = 0;
	if (!str)
		return (0);
	while (x < g_x)
	{
		y = 0;
		while (y < 4)
			free(str[x][y++]);
		free(str[x++]);
	}
	while (x == g_x)
	{
		y = 0;
		while (y < g_y)
			free(str[x][y++]);
		free(str[x++]);
	}
	while (x <= 25)
		free(str[x++]);
	free(str);
	return (0);
}

char	***ft_checktetris(char ***tetr, int fd)
{
	int		i;

	while (get_next_line(fd, &g_line) == 1)
	{
		if (g_line[0] == '\0' && g_y == 4)
			if (!(ft_jumptetr(fd, tetr[g_x])))
				return (arrdel(tetr));
		if ((g_line[0] == '\0' && g_y != 4) || g_y >= 4)
			return (arrdel(tetr));
		i = -1;
		while (g_line[++i])
		{
			if (g_line[i] != '.' && g_line[i] != '#')
				return (arrdel(tetr));
			(g_line[i] == '#') ? g_z++ : g_z;
		}
		if (i != 4)
			return (arrdel(tetr));
		tetr[g_x][g_y++] = ft_changehesh(g_line, g_x);
	}
	if (get_next_line(fd, &g_line) == 2)
		return (arrdel(tetr));
	return ((g_z == 4 && ft_cnct(tetr[g_x], 'A' + g_x)) ? tetr : arrdel(tetr));
}

t_lst	*ft_cuttetr(char ***tetr, int count, t_lst *lst)
{
	int		i;
	int		h;
	t_lst	*tmp;

	tmp = lst;
	i = -1;
	while (++i < count)
	{
		h = ft_calcheight(tetr[i], 'A' + i);
		tmp->h = h;
		tmp->a = 'A' + i;
		tmp->w = 0;
		tmp->next = NULL;
		if (!(tmp->str = (char**)malloc(sizeof(char*) * h)))
			return (0);
		tmp = ft_filllst(tetr, i, tmp);
	}
	return (lst);
}

int		main(int argc, char **argv)
{
	char	***tetr;
	int		fd;
	int		count_tetr;
	t_lst	*lst;
	t_lst	*ptr;
	char **mtrx;
	int i;
	int nb;

	g_x = 0;
	g_y = 0;
	g_z = 0;
	if (argc != 2)
		ft_putendl("usage: ./fillit input_file\0");
	else
	{
		tetr = ft_malloc_tetr();
		fd = open(argv[1], O_RDONLY);
		if (!(tetr = ft_checktetris(tetr, fd)))
		{
			ft_putendl("error");
//			system("leaks fillit");
			return (0);
		}
		count_tetr = g_x + 1;
		printf("TETRIMINOS-%d\n", count_tetr);
		nb = ft_minsquare(count_tetr);
		printf("SQUARE-%d\n", nb);
		lst = (t_lst*)malloc(sizeof(t_lst));
		lst = ft_cuttetr(tetr, count_tetr, lst);
		ptr = lst;
		while (ptr->next)
		{
//			i = 0;
			printf("w-%d\n", ptr->w);
//			while(i < ptr->h)
//			{
//				ft_putendl(ptr->str[i++]);
//			}
			ptr = ptr->next;
		}
		mtrx = ft_solve(ft_createmtrx(nb), lst, nb);
		i = 0;
		while (i < nb)
		{
//			ft_putnbr(nb);
			ft_putendl(mtrx[i]);
			i++;
		}
		close(fd);
	}
//	system("leaks fillit");
	return (0);
}
