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
# include "parse.h"
# include "map.h"
# include "controls.h"
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

typedef struct	s_env
{
	SDL_Window		*win;
	t_map			map;
	t_ogl			ogl;
	t_controls		controls;
	int				x_win;
	int				y_win;
	int				quit;
}				t_env;

void			lem_in_visu(void);
t_map			parse_to_map(t_parse parse);
void			init_env(t_env *e);

int				render(t_env *e);

void			handle_events(t_env *e);

void			clean_env(t_env e);

#endif
