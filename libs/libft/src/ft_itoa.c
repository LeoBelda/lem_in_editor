/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:38:32 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/29 15:52:08 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t	ft_abs(intmax_t n)
{
	return (n > 0 ? n : -n);
}

static size_t	ft_get_size(intmax_t n)
{
	size_t	size;

	size = 0;
	if (n < 0)
		size++;
	while (1)
	{
		n /= 10;
		size++;
		if (!n)
			break ;
	}
	return (size);
}

char			*ft_itoa(intmax_t n)
{
	char			*str;
	size_t			len;
	size_t			i;

	i = 0;
	len = ft_get_size(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	while (1)
	{
		str[--len] = ft_abs(n % 10) + 48;
		n /= 10;
		if (!n)
			break ;
	}
	return (str);
}
