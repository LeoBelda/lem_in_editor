/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:56:15 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 12:32:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*parse_shader(const char *shader_path)
{
	int		fd;
	int		ret;
	char	buf[16];
	char	*source;
	char	*tmp;

	source = NULL;
	if ((fd = open(shader_path, O_RDONLY)) == -1)
		error_exit("");
	while ((ret = read(fd, buf, 16)))
	{
		if (ret == -1)
			error_exit("read problem while parsing shader");
		tmp = source;
		source = (source ? ft_strnjoin(source, buf, ret)
						: ft_strndup(buf, ret));
		if (!source)
			error_exit("malloc problem while parsing shader");
		if (tmp)
			free(tmp);
	}
	if (close(fd) == -1)
		error_exit("");
	return (source);
}

void	print_compile_errors(GLuint shader, int exit)
{
	char	buf[1024];

	glGetShaderInfoLog(shader, 1024, NULL, buf);
	ft_putendl_fd(buf, 2);
	if (exit)
		error_exit("Shader compilation error");
}

void	print_link_errors(GLuint program)
{
	char	buf[1024];

	glGetProgramInfoLog(program, 1024, NULL, buf);
	ft_putendl_fd(buf, 2);
	error_exit("Program linking error");
}

void	check_glerror(void)
{
	GLenum	err;

	while ((err = glGetError()) != GL_NO_ERROR)
	{
		if (err == GL_INVALID_ENUM)
			ft_putendl_fd("gl invalid enum", 2);
		if (err == GL_INVALID_VALUE)
			ft_putendl_fd("gl invalid value", 2);
		if (err == GL_INVALID_OPERATION)
			ft_putendl_fd("gl invalid operation", 2);
		if (err == GL_INVALID_FRAMEBUFFER_OPERATION)
			ft_putendl_fd("gl invalid framebuffer operation", 2);
		if (err == GL_OUT_OF_MEMORY)
			ft_putendl_fd("gl out of memory", 2);
		error_exit("");
	}
}
