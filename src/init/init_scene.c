#include "map.h"
#include "scene.h"

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
	glBindBuffer(GL_UNIFORM_BUFFER, scene.ubo);
	glBindBufferBase(GL_UNIFORM_BUFFER, U_BINDING1, scene.ubo);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(t_mat4), NULL, GL_STREAM_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

static void			init_link_buffers(t_scene scene)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos[VBO_TRANS]);
	glEnableVertexAttribArray(VBO_TRANS);
	glVertexAttribPointer(VBO_TRANS, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos[VBO_STATE]);
	glEnableVertexAttribArray(VBO_STATE);
	glVertexAttribPointer(VBO_STATE, 1, GL_INT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene.ibos[IBO_LINK]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			scene.nb_links * 2 * sizeof(GLuint),
			scene.link_indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

static void			init_instances_buffers(t_scene scene)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos[VBO_TRANS]);
	glBufferData(GL_ARRAY_BUFFER,
			scene.nb_rooms * sizeof(GLfloat) * 2,
			scene.room_positions, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VBO_TRANS);
	glVertexAttribPointer(VBO_TRANS, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glVertexAttribDivisor(VBO_TRANS, 1);
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos[VBO_STATE]);
	glBufferData(GL_ARRAY_BUFFER,
			scene.nb_rooms * sizeof(GLint),
			NULL, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VBO_STATE);
	glVertexAttribPointer(VBO_STATE, 2, GL_BYTE, GL_FALSE, 0, NULL);
	glVertexAttribDivisor(VBO_STATE, 1);
}

static void			init_room_buffers(t_scene scene, t_mesh mod)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos[VBO_MODEL_COORDS]);
	glBufferData(GL_ARRAY_BUFFER,
			mod.nb_coords * sizeof(GLfloat) * 2,
			mod.coords, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scene.ibos[IBO_ROOM]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			mod.nb_indices * sizeof(GLuint),
			mod.indices, GL_STATIC_DRAW);
}

t_scene				init_scene(t_map map)
{
	t_scene	scene;

	scene.programs[PROG_ROOM] = build_ogl_program(VTX_ROOM, FRG_ROOM);
	scene.programs[PROG_LINK] = build_ogl_program(VTX_LINK, FRG_LINK);
	scene.nb_rooms = map.nb_rooms;
	scene.nb_links = map.nb_links;
	scene.room_positions = get_room_positions(map.rooms, map.nb_rooms);
	scene.link_indices = get_link_indices(map.links, map.nb_links);
	scene.room_model = create_room_model();
	glGenVertexArrays(VAO_MAX, scene.vaos);
	glGenBuffers(VBO_MAX, scene.vbos);
	glGenBuffers(IBO_MAX, scene.ibos);
	glGenBuffers(1, &scene.ubo);
	init_uniforms(scene);
	glUseProgram(scene.programs[PROG_ROOM]);
	glBindVertexArray(scene.vaos[VAO_ROOM]);
	init_room_buffers(scene, scene.room_model);
	init_instances_buffers(scene);
	glUseProgram(scene.programs[PROG_LINK]);
	glBindVertexArray(scene.vaos[VAO_LINK]);
	init_link_buffers(scene);
	glUseProgram(0);
	glBindVertexArray(0);
	return (scene);
}
