/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:12:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/30 19:05:41 by lbelda           ###   ########.fr       */
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
	ft_lstdel(&map->rooms, lstdel_room);
}

void			clean_env(t_env *e)
{
	clean_map(&e->map);
	clean_gl_objects(&e->scene);
	SDL_GL_DeleteContext(e->ogl.context);
	SDL_DestroyWindow(e->win);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_Quit();
}
