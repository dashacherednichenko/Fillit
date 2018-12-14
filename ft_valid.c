/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:30:10 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/13 18:18:07 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		ft_checksn(int fd, char **argv)
{
	int		rb;
	char	str[BUFF_SIZE];

	close(fd);
	fd = open(argv[1], O_RDONLY);
	rb = (read(fd, str, BUFF_SIZE) - 1);
	close(fd);
	if (str[rb] == '\n')
		return (1);
	return (0);
}

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
	while (ft_sqrt(n) == 0)
		n++;
	return (ft_sqrt(n));
}

char	***ft_malloc_tetr(void)
{
	char	***tetr;
	int		x;
	int		y;

	x = -1;
	if (!(tetr = (char***)malloc(sizeof(char**) * 26)))
		return (0);
	while (++x < 26)
	{
		y = 0;
		if (!(tetr[x] = (char**)malloc(sizeof(char*) * 4)))
			return (0);
	}
	return (tetr);
}
