/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:12:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/31 10:46:26 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		clean_gl_objects(t_scene *scene)
{
	int	i;

	glDeleteVertexArrays(VAO_MAX, scene->vaos);
	glDeleteBuffers(VBO_MAX, scene->vbos_room);
	glDeleteBuffers(VBO_MAX_LK, scene->vbos_link);
	glDeleteBuffers(IBO_MAX, scene->ibos);
	glDeleteBuffers(UBO_MAX, scene->ubos);
	i = -1;
	while (++i < PROG_MAX)
		glDeleteProgram(scene->programs[i]);
}

static void		clean_map(t_map *map)
{
	int	i;

	i = -1;
	ft_lstdel(&map->rooms, lstdel_room);
	ft_lstdel(&map->links, lstdel_link);
	if (map->turns)
		while (map->turns[++i])
			free_pro((void**)&map->turns[i]);
	free_pro((void**)&map->turns);
}

static void		clean_scene(t_scene *scene)
{
	free_pro((void**)&scene->room_positions);
	free_pro((void**)&scene->room_states);
	free_pro((void**)&scene->link_positions);
	free_pro((void**)&scene->link_states);
	free_pro((void**)&scene->room_model.coords);
	free_pro((void**)&scene->room_model.indices);
}

void			clean_env(t_env *e)
{
	clean_map(&e->map);
	clean_scene(&e->scene);
	clean_gl_objects(&e->scene);
	SDL_GL_DeleteContext(e->ogl.context);
	SDL_DestroyWindow(e->win);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_Quit();
}
