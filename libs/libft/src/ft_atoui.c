/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:00:37 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 14:00:38 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_atoui(const char *str)
{
	size_t			i;
	uintmax_t		n;

	i = 0;
	n = 0;
	while (ft_iswhitespace((int)str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit((int)(str[i])))
	{
		n *= 10;
		n += (str[i] - 48);
		i++;
	}
	return (n);
}
