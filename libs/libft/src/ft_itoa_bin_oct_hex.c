/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:25:55 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/29 15:51:49 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_get_size(uintmax_t n, size_t bpc)
{
	size_t		size;
	uintmax_t	mask;

	size = sizeof(uintmax_t) << 3;
	mask = (uintmax_t)1 << (size - 1);
	while (!(mask & n) && mask)
	{
		size--;
		mask = mask >> 1;
	}
	return (size % bpc || size == 0 ? size / bpc + 1 : size / bpc);
}

static size_t	ft_get_bits_per_char(size_t base)
{
	uintmax_t	mask;
	size_t		bpc;

	bpc = 1;
	mask = 1 << 1;
	while (!(mask & base))
	{
		bpc++;
		mask = mask << 1;
	}
	return (bpc);
}

static char		ft_process_char(size_t len, size_t bpc, size_t n, size_t i)
{
	uintmax_t	mask;
	uintmax_t	decal;
	uintmax_t	offset;
	uintmax_t	max;
	char		val;

	decal = (len - i) * bpc;
	max = sizeof(uintmax_t) << 3;
	if (decal > max)
	{
		offset = decal - max;
		bpc -= offset;
		decal -= offset;
	}
	mask = (uintmax_t)1 << (decal - 1);
	val = 0;
	while (bpc)
	{
		val += (((mask & n) || 0) * (1 << (bpc - 1)));
		mask = mask >> 1;
		bpc--;
	}
	return (val < 10 ? val + 48 : val + 87);
}

char			*ft_itoa_bin_oct_hex(uintmax_t n, size_t base)
{
	char		*str;
	size_t		len;
	size_t		bpc;
	size_t		i;

	i = 0;
	bpc = ft_get_bits_per_char(base);
	len = ft_get_size(n, bpc);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		str[i] = ft_process_char(len, bpc, n, i);
		i++;
	}
	return (str);
}
