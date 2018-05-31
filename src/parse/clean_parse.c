/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:30:13 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/31 10:45:36 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "visu.h"

static void	lstdel_moveparse(void *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free_pro((void**)&(((t_moveparse*)content)[i].name));
		i++;
	}
	free_pro((void**)&content);
}

void		clean_parse(t_parse parse)
{
	ft_lstdel(&parse.turns, lstdel_moveparse);
}

void		clean_parse_full(t_parse parse)
{
	ft_lstdel(&parse.rooms, lstdel_room);
	ft_lstdel(&parse.links, lstdel_link);
	ft_lstdel(&parse.turns, lstdel_moveparse);
}
