/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdels.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:07:50 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 13:07:52 by lbelda           ###   ########.fr       */
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
