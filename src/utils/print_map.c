/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:39:28 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/30 17:05:23 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ft_printf.h"

void	print_map(t_map map)
{
	t_room	*rcur;
	t_link	*lcur;

	ft_printf("%ju\n", map.nb_ants);
	while (map.rooms)
	{
		rcur = (t_room*)(map.rooms->content);
		if (map.start == rcur)
			ft_printf("##start\n");
		else if (map.end == rcur)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", rcur->name,
				(int)rcur->coords.x, (int)rcur->coords.y);
		map.rooms = map.rooms->next;
	}
	while (map.links)
	{
		lcur = (t_link*)(map.links->content);
		ft_printf("%s-%s\n", lcur->a->name, lcur->b->name);
		map.links = map.links->next;
	}
}
