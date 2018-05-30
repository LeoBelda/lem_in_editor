/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdels.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:07:50 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/30 19:07:10 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "objects.h"
#include "map.h"

void	lstdel_moveparse(void *content, size_t size)
{
	(void)size;
	free_pro((void**)&(((t_moveparse*)content)->name));
}

void	lstdel_room(void *content, size_t size)
{
	(void)size;
	ft_lstdel(&(((t_room*)content)->links), lstdel_linkref);
	ft_lstdel(&(((t_room*)content)->p_links), lstdel_linkref);
	free_pro((void**)&(((t_room*)content)->name));
	free_pro((void**)&content);
}

void	lstdel_linkref(void *content, size_t size)
{
	(void)size;
	(void)content;
}

void	lstdel_link(void *content, size_t size)
{
	(void)size;
	free_pro((void**)&content);
}
