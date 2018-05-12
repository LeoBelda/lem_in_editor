/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:59:00 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/24 16:35:19 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_append_free(char **s1, char **s2)
{
	char	*s;

	if (!*s1 || !*s2)
		return (-1);
	if (!(s = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2))))
	{
		free((void*)s2);
		*s2 = NULL;
		return (-1);
	}
	s = ft_strcat(ft_strcpy(s, *s1), *s2);
	free((void*)*s1);
	*s1 = s;
	free((void*)*s2);
	*s2 = NULL;
	return (0);
}
