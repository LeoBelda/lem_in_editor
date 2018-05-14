#ifndef OGL_UTILS_H
# define OGL_UTILS_H

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
# else
#  include <GL/glew.h>
# endif

# include "libft.h"
# include "printf.h"
# include "fcntl.h"
# include "common.h"

typedef struct	s_glfloat2
{
	GLfloat	x;
	GLfloat	y;
}				t_glfloat2;

typedef struct	s_glfloat3
{
	GLfloat	x;
	GLfloat	y;
	GLfloat	z;
}				t_glfloat3;

GLuint			build_ogl_program(const char *vtx_path, const char *frag_path);

char			*parse_shader(const char *shader_path);
void			print_compile_errors(GLuint shader, int exit);
void			print_link_errors(GLuint program);
void			check_glerror(void);

#endif
