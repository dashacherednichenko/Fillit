/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:51:27 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/02 15:28:42 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istab(char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || s == '\r'\
			|| s == '\v' || s == '\f')
		return (1);
	return (0);
}

static int	ft_isnb(char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					ii;
	unsigned long long	nb;

	i = 0;
	nb = 0;
	while (ft_istab(str[i]) == 1 && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isnb(str[i + 1]) == 1)
		i++;
	ii = i - 1;
	while (ft_isnb(str[i]) == 1 && str[i] != '\0')
	{
		nb = nb + str[i] - '0';
		if (ft_isnb(str[i + 1]) == 1 && str[i + 1] != '\0')
			nb = nb * 10;
		i++;
	}
	if (nb > 9223372036854775807 && str[ii] == '-')
		return (0);
	if (nb > 9223372036854775807)
		return (-1);
	if (str[ii] == '-')
		return (-((int)nb));
	return ((int)nb);
}
