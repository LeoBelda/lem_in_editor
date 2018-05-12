/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:01:16 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/25 17:32:38 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_fill(size_t size, char c)
{
	char	*str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	ft_memset((void*)str, c, size);
	str[size] = '\0';
	return (str);
}
