/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:58:03 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/05 20:54:09 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ismin(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_len(long long nb, int ii)
{
	while (nb >= 10)
	{
		nb = nb / 10;
		ii++;
	}
	return (ii);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			ii;
	long long	nb;
	long long	nbr;

	nb = n;
	ii = ft_ismin(n);
	if (ii == 1)
		nb = -1 * nb;
	nbr = nb;
	ii = ft_len(nb, ii);
	str = ft_strnew(ii + 1);
	if (str == 0)
		return (0);
	while (nbr >= 10)
	{
		str[ii--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	str[ii] = nbr + 48;
	if (ft_ismin(n) == 1)
		str[ii - 1] = '-';
	return (str);
}
