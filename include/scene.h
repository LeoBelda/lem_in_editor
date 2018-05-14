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

typedef struct	s_mesh
{
	t_glfloat2	*coords;
	t_glfloat2	*indices;
}				t_model;

typedef struct	s_model
{
	GLuint	program;
	GLuint	vao;
	GLuint	vbo;
	GLsizei	vbo_size;
	GLuint	ibo;
	GLsizei	ibo_size;
	t_mesh	mesh;
}				t_model;

typedef struct	s_scene
{
	t_model	rooms;
	t_model	links;
}				t_scene;

#endif
