/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:12:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:12:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "controls.h"
#include "ogl_utils.h"

static void	render_rooms(t_scene scene)
{
	glUseProgram(scene.programs[PROG_ROOM]);
	glBindVertexArray(scene.vaos[VAO_ROOM]);
	glDrawElementsInstanced(GL_TRIANGLES,
			scene.room_model.nb_indices, GL_UNSIGNED_INT, NULL,
			scene.nb_rooms);
	glBindVertexArray(0);
	glUseProgram(0);
}

static void	render_links(t_scene scene)
{
	glUseProgram(scene.programs[PROG_LINK]);
	glBindVertexArray(scene.vaos[VAO_LINK]);
	glDrawElements(GL_LINES,
			scene.nb_links * 2, GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);
	glUseProgram(0);
}

int		render(t_env *e)
{
	while (!e->quit)
	{
		handle_events(e);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		update_camera(e->scene, e->matrices);
		render_rooms(e->scene);
		render_links(e->scene);
		check_glerror();
		SDL_GL_SwapWindow(e->win);
	}
	clean_env(*e);
	return (0);
}