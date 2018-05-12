/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:42:50 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/12 13:47:19 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*s;
	size_t	length;

	length = ft_strlen(s2) < n ? ft_strlen(s2) : n;
	if (!s1 || !s2)
		return (NULL);
	if (!(s = ft_strnew(ft_strlen(s1) + length)))
		return (NULL);
	return (ft_strncat(ft_strcpy(s, s1), s2, length));
}
