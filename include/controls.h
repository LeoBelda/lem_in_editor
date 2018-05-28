/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:28:41 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 15:15:08 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "SDL.h"
# include "objects.h"
# include "map.h"
# include "scene.h"

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
	KB_E,
	KB_SPACE,
	KB_ESCAPE,
	KB_MAX
};

enum			e_ms_funcs
{
	MS_RIGHT,
	MS_LEFT,
	MS_MAX
};

enum			e_ms_attached
{
	MS_A_NONE,
	MS_A_ROOM,
	MS_A_LINK
}				t_ms_attached;

typedef struct	s_kb_lookup
{
	SDL_Keycode	sym;
	void		(*func)(void *e, int type);
}				t_kb_lookup;

typedef struct	s_ms_lookup
{
	uint8_t		button;
	void		(*func)(void *e, int type, int x, int y);
}				t_ms_lookup;

typedef union	u_object
{
	t_room				*room;
	t_link				*link;
}				t_object;

typedef struct	s_controls
{
	t_kb_lookup			kb_lookup[KB_MAX];
	t_ms_lookup			ms_lookup[MS_MAX];
	t_object			attached;
	enum e_ms_attached	which;
}				t_controls;

void			kb_forward(void *e, int type);
void			kb_backward(void *e, int type);
void			kb_play(void *e, int type);
void			kb_start(void *e, int type);
void			kb_end(void *e, int type);
void			kb_quit(void *e, int type);
void			kb_debug(void *e, int type);
void			kb_none(void *e, int type);

void			ms_room(void *e, int type, int x, int y);
void			ms_bind(void *e, int type, int x, int y);
void			ms_move(void *e, SDL_MouseMotionEvent motion);

void			refresh_room(t_scene *scene, t_map map, int id);
void			refresh_rooms_from(t_scene *scene, t_map map, int id);
t_room			*find_closest_room(t_list *rooms, t_vec2 mouse);

void			remove_link_dep(t_list **links, int id);
t_link			*check_duplicate(t_room tar, t_room *a);
void			refresh_link(t_scene *scene, t_map map, int id,
										t_vec2 b_coords);
void			refresh_related_links(t_scene *scene, t_map map,
											t_list *links);
void			refresh_all_links(t_scene *scene, t_map map);

#endif
