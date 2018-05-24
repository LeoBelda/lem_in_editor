/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:28:28 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 13:31:12 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "debug.h"

t_glfloat2	*get_room_positions(t_list *rooms, int nb_rooms)
{
	t_glfloat2	*positions;
	int			i;

	m_pro_null(positions = ft_memalloc(nb_rooms * sizeof(t_glfloat2)));
	i = 0;
	while (rooms)
	{
		positions[i++] = (t_glfloat2) {((t_room*)rooms->content)->coords.x,
								((t_room*)rooms->content)->coords.y};
		rooms = rooms->next;
	}
	return (positions);
}

t_glfloat2	*get_link_positions(t_list *links, int nb_links)
{
	t_glfloat2	*positions;
	int			i;

	m_pro_null(positions = ft_memalloc(nb_links * sizeof(t_glfloat2) * 2));
	i = 0;
	while (links)
	{
		positions[i++] = (t_glfloat2) {((t_link*)links->content)->a->coords.x,
					((t_link*)links->content)->a->coords.y};
		positions[i++] = (t_glfloat2) {((t_link*)links->content)->b->coords.x,
					((t_link*)links->content)->b->coords.y};
		links = links->next;
	}
	return (positions);
}

void		init_gl_objects(t_scene *scene)
{
	glGenVertexArrays(VAO_MAX, scene->vaos);
	glGenBuffers(VBO_MAX, scene->vbos_room);
	glGenBuffers(VBO_MAX_LK, scene->vbos_link);
	glGenBuffers(IBO_MAX, scene->ibos);
	glGenBuffers(UBO_MAX, scene->ubos);
}
