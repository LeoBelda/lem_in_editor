/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:27:32 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 14:06:01 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "scene.h"
#include "visu.h"

#define VTX_ROOM "src/shaders/room.vtx"
#define FRG_ROOM "src/shaders/room.frg"
#define VTX_LINK "src/shaders/link.vtx"
#define FRG_LINK "src/shaders/link.frg"

static void			init_uniforms(t_scene scene)
{
	int	i;

	i = -1;
	while (++i < PROG_MAX)
	{
		glUseProgram(scene.programs[i]);
		scene.u_block[i] =
			glGetUniformBlockIndex(scene.programs[i], "matrixBlock");
		glUniformBlockBinding(scene.programs[i], scene.u_block[i], U_BINDING1);
		glUseProgram(0);
	}
	glBindBuffer(GL_UNIFORM_BUFFER, scene.ubos[UBO_0]);
	glBindBufferBase(GL_UNIFORM_BUFFER, U_BINDING1, scene.ubos[UBO_0]);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(t_mat4) + sizeof(float) * 2.,
									NULL, GL_STREAM_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

static void			init_link_buffers(t_scene scene)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_link[VBO_MODEL_COORDS_LK]);
	glBufferData(GL_ARRAY_BUFFER,
				sizeof(t_glfloat2) * 2 * E_LINK_MAX,
				scene.link_positions, GL_STREAM_DRAW);
	glEnableVertexAttribArray(VBO_MODEL_COORDS_LK);
	glVertexAttribPointer(VBO_MODEL_COORDS_LK, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_link[VBO_STATE_LK]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 2 * E_LINK_MAX,
				scene.link_states, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VBO_STATE_LK);
	glVertexAttribPointer(VBO_STATE_LK, 1, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

static void			init_instances_buffers(t_scene scene)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_room[VBO_TRANS]);
	glBufferData(GL_ARRAY_BUFFER,
			sizeof(GLfloat) * 2 * E_ROOM_MAX,
			scene.room_positions, GL_STREAM_DRAW);
	glEnableVertexAttribArray(VBO_TRANS);
	glVertexAttribPointer(VBO_TRANS, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glVertexAttribDivisor(VBO_TRANS, 1);
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_room[VBO_STATE]);
	glBufferData(GL_ARRAY_BUFFER,
			sizeof(GLint) * 2 * E_ROOM_MAX,
			NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(VBO_STATE);
	glVertexAttribPointer(VBO_STATE, 2, GL_INT, GL_FALSE, 0, NULL);
	glVertexAttribDivisor(VBO_STATE, 1);
}

static void			init_room_buffers(t_scene scene, t_mesh mod)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_room[VBO_MODEL_COORDS]);
	glBufferData(GL_ARRAY_BUFFER,
			mod.nb_coords * sizeof(GLfloat) * 3,
			mod.coords, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VBO_MODEL_COORDS);
	glVertexAttribPointer(VBO_MODEL_COORDS, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene.ibos[IBO_ROOM]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			mod.nb_indices * sizeof(GLuint),
			mod.indices, GL_STATIC_DRAW);
}

t_scene				init_scene_edit(t_map map)
{
	t_scene	s;

	s.programs[PROG_ROOM] = build_ogl_program(VTX_ROOM, FRG_ROOM);
	s.programs[PROG_LINK] = build_ogl_program(VTX_LINK, FRG_LINK);
	s.nb_rooms = 0;
	s.nb_links = 0;
	m_pro_null(s.room_positions = ft_memalloc(sizeof(t_vec2) * E_ROOM_MAX));
	m_pro_null(s.room_states = ft_memalloc(sizeof(GLint) * E_ROOM_MAX));
	m_pro_null(s.link_positions =
			ft_memalloc(sizeof(GLfloat) * E_LINK_MAX * 2));
	m_pro_null(s.link_states = ft_memalloc(sizeof(GLfloat) * E_LINK_MAX * 2));
	s.room_model = create_room_model();
	s.timeline = (t_timeline){0., 0., -1, map.nb_turns, 0.};
	init_gl_objects(&s);
	init_uniforms(s);
	glUseProgram(s.programs[PROG_ROOM]);
	glBindVertexArray(s.vaos[VAO_ROOM]);
	init_room_buffers(s, s.room_model);
	init_instances_buffers(s);
	glUseProgram(s.programs[PROG_LINK]);
	glBindVertexArray(s.vaos[VAO_LINK]);
	init_link_buffers(s);
	glUseProgram(0);
	glBindVertexArray(0);
	return (s);
}
