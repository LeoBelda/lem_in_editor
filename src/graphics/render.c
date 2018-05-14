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

int		render(t_env *e)
{
	while (!e->quit)
	{
		handle_events(e);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		/*
		glUseProgram(v->ogl.program);
		glBindVertexArray(v->ogl.vao);
		glDrawElements(GL_TRIANGLE_STRIP, v->ogl.ibo_size,
						GL_UNSIGNED_INT, NULL);
		glBindVertexArray(0);
		glUseProgram(0);
		*/
		check_glerror();
		SDL_GL_SwapWindow(e->win);
	}
	clean_env(*e);
	return (0);
}
