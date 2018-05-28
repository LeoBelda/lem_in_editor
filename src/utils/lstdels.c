/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdels.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:07:50 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 10:49:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "objects.h"

void	lstdel_moveparse(void *content, size_t size)
{
	(void)size;
	free_pro((void**)&(((t_moveparse*)content)->name));
}

void	lstdel_room(void *content, size_t size)
{
	(void)size;
	free_pro((void**)&(((t_room*)content)->name));
}

void	lstdel_link(void *content, size_t size)
{
	(void)content;
	(void)size;
}
