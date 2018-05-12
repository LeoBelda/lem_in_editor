/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:48:03 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/26 17:00:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size(uintmax_t n)
{
	size_t	size;

	size = 0;
	if (n < 10)
		return (size + 1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_uitoa(uintmax_t n)
{
	char			*str;
	size_t			len;
	size_t			i;

	i = 0;
	len = ft_get_size(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 10)
		str[i] = n + 48;
	else
		while (n != 0)
		{
			str[--len] = n % 10 + 48;
			n /= 10;
		}
	return (str);
}
