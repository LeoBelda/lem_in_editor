/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:33:43 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 13:27:18 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

static void	finalize_link(t_env *e, t_vec2 coords)
{
	t_room	*target;

	if (!(target = find_closest_room(e->map.rooms, coords)))
	{
		e->scene.nb_links--;
		ft_lstdel_n(&e->map.links, e->scene.nb_links, lstdel_link);
		return ;
	}
	e->controls.attached.link->b = target;
	refresh_link(&e->scene, e->map,
					e->controls.attached.link->id,
					e->controls.attached.link->b->coords);
	m_pro(ft_lstadd(&e->controls.attached.link->a->links,
				ft_lstnewref(e->controls.attached.link, 0)));
	m_pro(ft_lstadd(&e->controls.attached.link->b->links,
				ft_lstnewref(e->controls.attached.link, 0)));
}

static void	add_link(t_env *e, t_room *target, t_list **links)
{
	t_link		new;
	t_list		*elem;

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
			e->controls.which = MS_A_LINK;
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
		if (env->controls.which == MS_A_LINK)
			finalize_link(env, (t_vec2){(float)x, (float)y});
		env->controls.attached.room = NULL;
		env->controls.which = MS_A_NONE;
	}
}
