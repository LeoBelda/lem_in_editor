/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:58:41 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 14:47:34 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# ifdef __APPLE__
#  include <OpenGL/gl3.h>
# else
#  include <GL/glew.h>
# endif

# include "SDL.h"
# include "common.h"
# include "libft.h"
# include "libftmath.h"

# define C_IGL_BLACK 0x00000000
# define C_IGL_WHITE 0xffffff00
# define C_IGL_RED 0xff000000
# define C_IGL_GREEN 0x00800000
# define C_IGL_BLUE 0x00008000

# define SDLK_MAX 128

typedef struct	s_ogl
{
	SDL_GLContext	context;
}				t_ogl;

typedef struct	s_visu
{
	SDL_Window		*win;
	t_ogl			ogl;
	int				x_win;
	int				y_win;
}				t_visu;

void			init_visu(t_visu *v);

void			clean_visu(t_visu v);

#endif
