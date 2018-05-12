/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:23:49 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 12:15:27 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdeplace(void *dst, const void *src, int fill, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	if (src < dst)
		while (len--)
		{
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
			((unsigned char*)src)[len] = (unsigned char)fill;
		}
	else
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			((unsigned char*)src)[i] = (unsigned char)fill;
			i++;
		}
	return (dst);
}
