/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:58:37 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:22:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
# else
#  include <GL/glew.h>
# endif

# include "unistd.h"
# include "fcntl.h"
# include "libft.h"
# include "ft_printf.h"

typedef struct	s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct	s_glfloat2
{
	GLfloat	x;
	GLfloat	y;
}				t_glfloat2;

typedef struct	s_glfloat3
{
	GLfloat	r;
	GLfloat	g;
	GLfloat	b;
}				t_glfloat3;

char			*parse_shader(const char *shader_path);
void			print_compile_errors(GLuint shader, int exit);
void			print_link_errors(GLuint program);
void			check_glerror(void);

void			init_quad_buffers(t_glfloat2 *coords, t_glfloat2 *uvs,
										GLuint *indices);
void			init_texture(void *data, t_vec2 dim,
					GLenum data_format, GLenum data_type);
GLint			init_sampler(GLuint program, const char *name, int num);

void			m_pro(int ret);
void			m_pro_null(void *ret);
void			free_pro(void **ptr);
void			map_error_exit(void);
void			error_exit(const char *str);

#endif
