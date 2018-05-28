/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:19:23 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 10:29:39 by lbelda           ###   ########.fr       */
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

void	refresh_rooms_from(t_scene *scene, t_map map, int id)
{
	t_list		*target;
	int			i;

	i = id - 1;
	target = ft_lstat(map.rooms, id - 1);
	while (target)
	{
		scene->room_positions[i] =
			(t_glfloat2) {((t_room*)(target->content))->coords.x,
						((t_room*)(target->content))->coords.y};
		i++;
		target = target->next;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_room[VBO_TRANS]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (id - 1) * 2,
			sizeof(GLfloat) * 2 * (i - (id - 1)),
				&scene->room_positions[id - 1]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void	refresh_room(t_scene *scene, t_map map, int id)
{
	t_room		*target;

	target = (t_room*)(ft_lstat(map.rooms, id - 1)->content);
	scene->room_positions[id - 1] =
			(t_glfloat2) {target->coords.x, target->coords.y};
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_room[VBO_TRANS]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (id - 1) * 2,
			sizeof(GLfloat) * 2, &scene->room_positions[id - 1]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
/*
void	refresh_links_from(t_scene *scene, t_map map, int id)
{
	t_list		*target;
	int			i;

	i = id - 1;
	target = ft_lstat(map.rooms, id - 1);
	while (target)
	{
		scene->link_positions[i] =
			(t_glfloat2) {((t_room*)(target->content))->coords.x,
						((t_room*)(target->content))->coords.y};
		i++;
		target = target->next;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_room[VBO_MODEL_COORDS_LK]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (id - 1) * 4,
			sizeof(GLfloat) * 4 * (i - (id - 1)),
				&scene->link_positions[id - 1]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

*/
void	refresh_link(t_scene *scene, t_map map, int id, t_vec2 b_coords)
{
	t_link	*target;

	target = (t_link*)(ft_lstat(map.links, id - 1)->content);
	scene->link_positions[(id - 1) * 2] =
			(t_glfloat2) {target->a->coords.x, target->a->coords.y};
	scene->link_positions[(id - 1) * 2 + 1] =
			(t_glfloat2) {b_coords.x, b_coords.y};
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_link[VBO_MODEL_COORDS_LK]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (id - 1) * 4,
			sizeof(GLfloat) * 4, &scene->link_positions[(id - 1) * 2]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
