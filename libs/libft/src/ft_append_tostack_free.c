/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_tostack_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:12:04 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/24 17:24:12 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_append_tostack_free(char **s1, char **s2)
{
	char	*s;

	if (!*s1 || !*s2)
		return (-1);
	if (!(s = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2))))
		return (-1);
	s = ft_strcat(ft_strcpy(s, *s1), *s2);
	free((void*)*s2);
	*s2 = s;
	return (0);
}
