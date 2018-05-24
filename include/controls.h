/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:28:41 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 10:28:42 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "SDL.h"

# define TM_INC 0.02

enum			e_kb_funcs
{
	KB_RIGHT,
	KB_LEFT,
	KB_DOWN,
	KB_UP,
	KB_D,
	KB_A,
	KB_S,
	KB_W,
	KB_P,
	KB_SPACE,
	KB_ESCAPE,
	KB_MAX
};

typedef struct	s_kb_lookup
{
	SDL_Keycode	sym;
	void		(*func)(void *e, int type);
}				t_kb_lookup;

typedef struct	s_controls
{
	t_kb_lookup			kb_lookup[KB_MAX];
}				t_controls;

t_controls		init_controls(void);

void			kb_forward(void *e, int type);
void			kb_backward(void *e, int type);
void			kb_play(void *e, int type);
void			kb_quit(void *e, int type);
void			kb_debug(void *e, int type);
void			kb_none(void *e, int type);

#endif
