#ifndef SCENE_H
# define SCENE_H

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
# else
#  include <GL/glew.h>
# endif

# include "libft.h"
# include "printf.h"
# include "common.h"
# include "ogl_utils.h"
# include "objects.h"

# define U_BINDING1 0

enum			e_vbos
{
	VBO_MODEL_COORDS,
	VBO_TRANS,
	VBO_STATE,
	VBO_MAX
};

enum			e_vbos_link
{
	VBO_MODEL_COORDS_LK,
	VBO_STATE_LK,
	VBO_MAX_LK
};

enum			e_ibos
{
	IBO_ROOM,
	IBO_MAX
};

enum			e_vaos
{
	VAO_ROOM,
	VAO_LINK,
	VAO_MAX
};

enum			e_ubos
{
	UBO_0,
	UBO_MAX
};

enum			e_programs
{
	PROG_ROOM,
	PROG_LINK,
	PROG_MAX
};

typedef struct	s_mesh
{
	t_glfloat3	*coords;
	int			nb_coords;
	GLuint		*indices;
	int			nb_indices;
}				t_mesh;

typedef struct	s_timeline
{
	float	progress;
	float	ratio;
	int		cur_turn;
	int		nb_turns;
	float	inc;
}				t_timeline;

typedef struct	s_scene
{
	GLuint		programs[PROG_MAX];
	GLuint		vaos[VAO_MAX];
	GLuint		ibos[IBO_MAX];
	GLuint		vbos_room[VBO_MAX];
	GLuint		vbos_link[VBO_MAX];
	GLuint		ubos[UBO_MAX];
	GLint		u_block[PROG_MAX];
	t_mesh		room_model;
	t_glfloat2	*room_positions;
	t_vec2r		*room_states;
	int			nb_rooms;
	t_glfloat2	*link_positions;
	GLfloat		*link_states;
	int			nb_links;
	t_timeline	timeline;
	float		ratio;
}				t_scene;

t_mesh			create_room_model(void);

t_glfloat2		*get_room_positions(t_list *rooms, int nb_rooms);
t_glfloat2		*get_link_positions(t_list *links, int nb_links);

#endif
