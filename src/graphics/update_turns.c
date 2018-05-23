#include "scene.h"
#include "map.h"

static void	update_room_states(t_scene *scene, t_map map, int cur_turn)
{
	size_t		i;

	ft_bzero(scene->room_states, sizeof(t_vec2r) * scene->nb_rooms);
	i = -1;
	while (map.turns[cur_turn][++i].start)
	{
		scene->room_states[map.turns[cur_turn][i].start->id].x = 1;
		scene->room_states[map.turns[cur_turn][i].end->id].y = 1;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_room[VBO_STATE]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(t_vec2r) * scene->nb_rooms,
								scene->room_states);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

static void	update_link_states(t_scene *scene, t_map map, int cur_turn)
{
	size_t		i;

	ft_floatset(scene->link_states, 0., 2 * scene->nb_links);
	i = -1;
	while (map.turns[cur_turn][++i].start)
	{
		if (map.turns[cur_turn][i].lk->a == map.turns[cur_turn][i].start)
			scene->link_states[map.turns[cur_turn][i].lk->id * 2] = 1.;
		else
			scene->link_states[map.turns[cur_turn][i].lk->id * 2 + 1] = 1.;
	}
	glBindBuffer(GL_ARRAY_BUFFER, scene->vbos_link[VBO_STATE_LK]);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 2 * scene->nb_links,
								scene->link_states);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void		update_turns(t_scene *scene, t_map map)
{
	scene->timeline.progress = ft_fclamp(0., (float)map.nb_turns - 0.01,
			scene->timeline.progress + scene->timeline.inc);
	scene->timeline.ratio = fmod(scene->timeline.progress, 1.0);
	if ((int)floorf(scene->timeline.progress) != scene->timeline.cur_turn)
	{
		scene->timeline.cur_turn = (int)floorf(scene->timeline.progress);
		update_room_states(scene, map, scene->timeline.cur_turn);
		update_link_states(scene, map, scene->timeline.cur_turn);
	}
}
