/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:31:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/25 16:35:12 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewref(void *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		elem->content_size = 0;
		elem->content = NULL;
	}
	else
	{
		elem->content = content;
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
