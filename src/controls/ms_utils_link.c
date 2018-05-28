/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:02:41 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 14:36:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	remove_link_dep(t_list **links, int id)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *links;
	while (tmp)
	{
		if (id == ((t_link*)(tmp->content))->id)
			break ;
		tmp = tmp->next;
		i++;
	}
	ft_lstdel_n(links, i, lstdel_linkref);
}


t_link	*check_duplicate(t_room tar, t_room *a)
{
	t_link	*check;

	while (tar.links)
	{
		check = (t_link*)(tar.links->content);
		if (check->a == a || check->b == a)
			return (check);
		tar.links = tar.links->next;
	}
	return (NULL);
}

void	refresh_all_links(t_scene *scene, t_map map)
{
	t_link		*target;
	int			i;

	i = 0;
	while (map.links)
	{
		target = (t_link*)(map.links->content);
		scene->link_positions[i++] =
			(t_glfloat2) {target->a->coords.x, target->a->coords.y};
		scene->link_positions[i++] =
			(t_glfloat2) {target->b->coords.x, target->b->coords.y};
		target->id = i / 2;
		map.links = map.links->next;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_link[VBO_MODEL_COORDS_LK]);
	glBufferSubData(GL_ARRAY_BUFFER, 0,
			sizeof(GLfloat) * 4 * scene->nb_links, scene->link_positions);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void	refresh_link(t_scene *scene, t_map map, int id, t_vec2 b_coords)
{
	t_link	*target;

	target = (t_link*)(ft_lstat(map.links, id - 1)->content);
	scene->link_positions[(id - 1) * 2] =
			(t_glfloat2) {target->a->coords.x, target->a->coords.y};
	scene->link_positions[(id - 1) * 2 + 1] =
			target->b ? (t_glfloat2){target->b->coords.x, target->b->coords.y}
					: (t_glfloat2) {b_coords.x, b_coords.y};
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_link[VBO_MODEL_COORDS_LK]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (id - 1) * 4,
			sizeof(GLfloat) * 4, &scene->link_positions[(id - 1) * 2]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void	refresh_related_links(t_scene *scene, t_map map, t_list *links)
{
	while (links)
	{
		refresh_link(scene, map, ((t_link*)(links->content))->id,
							(t_vec2){0., 0.});
		links = links->next;
	}
}
