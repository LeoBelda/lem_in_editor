/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:19:23 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/25 17:40:05 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

#define SENSITIVITY 30

t_room	*find_closest_room(t_list *rooms, t_vec2 mouse)
{
	t_room	*closest;
	t_room	*cur;
	float	min_dst;
	float	dst;

	closest = NULL;
	min_dst = 10000.;
	while (rooms)
	{
		cur = (t_room*)rooms->content;
		dst = vec2_distance(mouse, cur->coords);
		if (dst < min_dst && dst < SENSITIVITY)
		{
			closest = cur;
			min_dst = dst;
		}
		rooms = rooms->next;
	}
	return (closest);
}

void	refresh_rooms(t_scene *scene, t_map map)
{
	int			i;

	i = 0;
	while (map.rooms)
	{
		scene->room_positions[i] =
			(t_glfloat2) {((t_room*)map.rooms->content)->coords.x,
							((t_room*)map.rooms->content)->coords.y};
		map.rooms = map.rooms->next;
		i++;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_room[VBO_TRANS]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 2 * scene->nb_rooms,
								scene->room_positions);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
