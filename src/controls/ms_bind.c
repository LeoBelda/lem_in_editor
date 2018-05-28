/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:33:43 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 10:13:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

static void	add_link(t_env *e, t_room *target, t_list **links)
{
	t_link		new;
	t_list		*elem;

	e->controls.which = MS_A_LINK;
	e->scene.nb_links++;
	new = (t_link){e->scene.nb_links, target, NULL};
	m_pro_null(elem = ft_lstnew((void*)&new, sizeof(t_link)));
	e->controls.attached.link = (t_link*)elem->content;
	m_pro(ft_lstradd(links, elem));
}

static void	choose_bind(t_env *e, int x, int y)
{
	t_room	*target;

	if (SDL_GetModState() & KMOD_CTRL)
	{
		if ((e->controls.attached.room = find_closest_room(e->map.rooms,
								(t_vec2){(float)x, (float)y})))
			e->controls.which = MS_A_ROOM;
	}
	else
	{
		if ((target = find_closest_room(e->map.rooms,
								(t_vec2){(float)x, (float)y})))
		{
			add_link(e, target, &e->map.links);
			refresh_link(&e->scene, e->map,
					e->controls.attached.link->id,
					(t_vec2){(float)x, (float)y});
		}
	}
}

void		ms_bind(void *e, int type, int x, int y)
{
	t_env		*env;

	env = (t_env*)e;
	if (type == SDL_MOUSEBUTTONDOWN)
		choose_bind(env, x, y);
	else
	{
		env->controls.attached.room = NULL;
		env->controls.which = MS_A_NONE;
	}
}
