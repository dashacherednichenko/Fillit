/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:28:32 by dpiven            #+#    #+#             */
/*   Updated: 2018/11/10 14:03:33 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(unsigned value, int base)
{
	size_t len;

	len = 1;
	while (value >= (unsigned)base)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(int value, int base)
{
	char		*str;
	size_t		len;
	unsigned	nb;

	if (base < 2 || base > 16)
		return (NULL);
	nb = value;
	if (value < 0 && base != 10)
		nb = -value;
	if (base == 10)
		return (ft_itoa(value));
	len = ft_len(nb, base);
	str = ft_strnew(len + 1);
	while (nb >= (unsigned)base)
	{
		if ((nb % base) < 10)
			str[(len--) - 1] = (nb % base) + 48;
		else
			str[(len--) - 1] = 'A' + ((nb % base) - 10);
		nb = nb / base;
	}
	if (nb >= 10)
		nb = nb - 10 - 48 + 'A';
	str[len - 1] = nb + 48;
	return (str);
}
