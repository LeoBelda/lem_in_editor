/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:58:41 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/25 03:57:01 by lbelda           ###   ########.fr       */
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
# include "scene.h"
# include "matrices.h"
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

typedef enum	e_mode
{
	V_VISU,
	V_EDIT
}				t_mode;

typedef struct	s_env
{
	SDL_Window		*win;
	t_map			map;
	t_scene			scene;
	t_ogl			ogl;
	t_matrices		matrices;
	t_controls		controls;
	int				x_win;
	int				y_win;
	float			ratio;
	t_mode			mode;
	int				quit;
}				t_env;

void			lem_in_visu(t_mode mode);
t_map			parse_to_map(t_parse parse);
void			init_env(t_env *e);
t_scene			init_scene(t_map map);
t_controls		init_controls(t_mode mode);
t_matrices		init_matrices(t_map map, float ratio);

int				render(t_env *e);
void			update_uniforms(t_scene scene, t_matrices mat);
void			update_turns(t_scene *scene, t_map map);

void			handle_events(t_env *e);

void			clean_env(t_env e);

#endif
