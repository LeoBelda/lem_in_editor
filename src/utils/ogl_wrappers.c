/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ogl_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:31:59 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:32:00 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	init_quad_buffers(t_glfloat2 *coords, t_glfloat2 *uvs, GLuint *indices)
{
	coords[0] = (t_glfloat2){-1., 1.};
	coords[1] = (t_glfloat2){-1., -1.};
	coords[2] = (t_glfloat2){1., 1.};
	coords[3] = (t_glfloat2){1., -1.};
	uvs[0] = (t_glfloat2){0., 1.};
	uvs[1] = (t_glfloat2){0., 0.};
	uvs[2] = (t_glfloat2){1., 1.};
	uvs[3] = (t_glfloat2){1., 0.};
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 3;
}

GLint	init_sampler(GLuint program, const char *name, int num)
{
	GLint	sampler;

	sampler = glGetUniformLocation(program, name);
	glUniform1i(sampler, num);
	return (sampler);
}

void	init_texture(void *data, t_vec2 dim,
					GLenum data_format, GLenum data_type)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, data_format, dim.x, dim.y, 0,
				data_format, data_type, data);
}
