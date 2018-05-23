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
	glBindBuffer(GL_UNIFORM_BUFFER, scene.ubos[UBO_0]);
	glBindBufferBase(GL_UNIFORM_BUFFER, U_BINDING1, scene.ubos[UBO_0]);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(t_mat4) + sizeof(float),
									NULL, GL_STREAM_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

static void			init_link_buffers(t_scene scene)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_link[VBO_MODEL_COORDS_LK]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_glfloat2) * scene.nb_links * 2,
				scene.link_positions, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VBO_MODEL_COORDS_LK);
	glVertexAttribPointer(VBO_MODEL_COORDS_LK, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_link[VBO_STATE_LK]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * scene.nb_links * 2,
				NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(VBO_STATE_LK);
	glVertexAttribPointer(VBO_STATE_LK, 1, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

static void			init_instances_buffers(t_scene scene)
{
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_room[VBO_TRANS]);
	glBufferData(GL_ARRAY_BUFFER,
			scene.nb_rooms * sizeof(GLfloat) * 2,
			scene.room_positions, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VBO_TRANS);
	glVertexAttribPointer(VBO_TRANS, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glVertexAttribDivisor(VBO_TRANS, 1);
	glBindBuffer(GL_ARRAY_BUFFER, scene.vbos_room[VBO_STATE]);
	glBufferData(GL_ARRAY_BUFFER,
			scene.nb_rooms * sizeof(GLint) * 2,
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

t_scene				init_scene(t_map map)
{
	t_scene	scene;

	scene.programs[PROG_ROOM] = build_ogl_program(VTX_ROOM, FRG_ROOM);
	scene.programs[PROG_LINK] = build_ogl_program(VTX_LINK, FRG_LINK);
	scene.nb_rooms = map.nb_rooms;
	scene.nb_links = map.nb_links;
	scene.room_positions = get_room_positions(map.rooms, map.nb_rooms);
	scene.link_positions = get_link_positions(map.links, map.nb_links);
	scene.room_model = create_room_model();
	scene.timeline = (t_timeline){0., 0., -1, map.nb_turns, 0.};
	m_pro_null(scene.room_states = ft_memalloc(sizeof(t_vec2r) * scene.nb_rooms));
	m_pro_null(scene.link_states = ft_memalloc(sizeof(GLfloat) * scene.nb_links * 2));
	glGenVertexArrays(VAO_MAX, scene.vaos);
	glGenBuffers(VBO_MAX, scene.vbos_room);
	glGenBuffers(VBO_MAX_LK, scene.vbos_link);
	glGenBuffers(IBO_MAX, scene.ibos);
	glGenBuffers(UBO_MAX, scene.ubos);
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
