/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:39:32 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/01 17:40:36 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_light(char *str, size_t base, intmax_t n)
{
	char			tmp;
	int				i;
	int				j;

	i = -1;
	if (n < 0)
		n = -n;
	while (++i != -1)
	{
		str[i] = (n % base) + 48;
		str[i] += (str[i] > '9' ? 39 : 0);
		n /= base;
		if (!n)
			break ;
	}
	j = i + 1;
	i = 0;
	while (--j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return (str);
}
