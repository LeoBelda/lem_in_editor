/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ogl_program.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:15:40 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:15:41 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ogl_utils.h"

#define I_VTX 0
#define I_FRAG 1
#define NB_SHAD 2

static GLuint	init_shader(GLenum type, const char *shader_source)
{
	GLuint	shader;
	GLint	ret;

	shader = glCreateShader(type);
	glShaderSource(shader, 1, &shader_source, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &ret);
	if (ret == GL_FALSE)
		print_compile_errors(shader, 1);
	glReleaseShaderCompiler();
	free_pro((void**)&shader_source);
	return (shader);
}

GLuint			build_program(const char *vtx_path, const char *frag_path)
{
	GLint	ret;
	GLuint	program;
	GLuint	vtxshader;
	GLuint	fragshader;

	vtxshader = init_shader(GL_VERTEX_SHADER,
								parse_shader(vtx_path));
	fragshader = init_shader(GL_FRAGMENT_SHADER,
								parse_shader(frag_path));
	program = glCreateProgram();
	glAttachShader(program, vtxshader);
	glAttachShader(program, fragshader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &ret);
	if (ret == GL_FALSE)
		print_link_errors(program);
	return (program);
}
