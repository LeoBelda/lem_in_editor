/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnowhitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:09:07 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/11 15:12:10 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpynowhitespace(char *dst, char const *src)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (src[++i])
		if (src[i] != ' ')
		{
			dst[j] = src[i];
			j++;
		}
}

size_t	ft_countnowhitespace(char const *str)
{
	int		i;
	size_t	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] != ' ')
			count++;
	return (count);
}

char	*ft_strnowhitespace(char const *str)
{
	char	*ret;
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] != ' ')
			count++;
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] != ' ')
		{
			ret[count] = str[i];
			count++;
		}
	ret[count] = '\0';
	return (ret);
}
