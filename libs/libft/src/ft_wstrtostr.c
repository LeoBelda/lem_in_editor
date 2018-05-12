/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:04:25 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 12:28:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrtostr(const wchar_t *wstr, int size, int *out_size)
{
	char	tmp[size * sizeof(wchar_t)];
	char	*ret;
	int		char_size;
	int		wchar;
	int		i;

	*out_size = 0;
	i = 0;
	while (wstr[i])
	{
		if ((wchar = ft_wctoi(wstr[i], &char_size)) == -1)
			return (NULL);
		if (*out_size + char_size <= size)
		{
			ft_memcpy(&tmp[*out_size], &wchar, char_size);
			*out_size += char_size;
		}
		else
			break ;
		i++;
	}
	if (!(ret = ft_memalloc((size_t)*out_size)))
		return (NULL);
	ft_memcpy(ret, tmp, *out_size);
	return (ret);
}
