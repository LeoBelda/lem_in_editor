#include "scene.h"
#include "map.h"

#define FPS_REFRESH 120

void	update_turns(t_scene *scene, t_map *map)
{
	static int	timer = FPS_REFRESH;
	size_t		i;

	if (timer == FPS_REFRESH && map->turns)
	{
		ft_bzero(scene->states, sizeof(t_vec2r) * scene->nb_rooms);
		i = 0;
		while (i < map->turns->content_size)
		{
			scene->states[((t_move*)map->turns->content)[i].start->id].x
				= 1;
			scene->states[((t_move*)map->turns->content)[i].end->id].y
				= 1;
			i++;
		}
		glBindBuffer(GL_ARRAY_BUFFER, scene->vbos[VBO_STATE]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLint) * 2 * scene->nb_rooms,
									scene->states);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		map->turns = map->turns->next;
		timer = 0;
	}
	timer++;
	scene->ratio = (float)timer / (float)FPS_REFRESH;
}
