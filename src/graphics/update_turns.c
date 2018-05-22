#include "scene.h"
#include "map.h"

#define FPS_REFRESH 120

static void	update_room_states(t_scene *scene, t_map *map)
{
	size_t		i;

	ft_bzero(scene->room_states, sizeof(t_vec2r) * scene->nb_rooms);
	i = 0;
	while (i < map->turns->content_size)
	{
		scene->room_states[((t_move*)map->turns->content)[i].start->id].x = 1;
		scene->room_states[((t_move*)map->turns->content)[i].end->id].y = 1;
		i++;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_room[VBO_STATE]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLint) * 2 * scene->nb_rooms,
								scene->room_states);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

static void	update_link_states(t_scene *scene, t_map *map)
{
	size_t		i;

	ft_floatset(scene->link_states, 0., 2 * scene->nb_links);
	i = 0;
	while (i < map->turns->content_size)
	{
		if (((t_move*)map->turns->content)[i].lk->a ==
				((t_move*)map->turns->content)[i].start)
			scene->link_states[((t_move*)map->turns->content)[i].lk->id * 2]
				= 1.;
		else
			scene->link_states[((t_move*)map->turns->content)[i].lk->id * 2 + 1]
				= 1.;
		i++;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_link[VBO_STATE_LK]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 2 * scene->nb_links,
								scene->link_states);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void		update_turns(t_scene *scene, t_map *map)
{
	static int	timer = FPS_REFRESH;

	if (timer == FPS_REFRESH && map->turns)
	{
		update_room_states(scene, map);
		update_link_states(scene, map);
		map->turns = map->turns->next;
		timer = 0;
	}
	timer++;
	scene->ratio = (float)timer / (float)FPS_REFRESH;
}
