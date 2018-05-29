/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:55:55 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/29 19:52:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

static void	add_room(t_vec2 coords, int id, t_list **rooms)
{
	t_room		new;
	static int	i = 1;

	new = (t_room){id, ft_itoa(i++), coords, NULL};
	m_pro(ft_lstradd(rooms, ft_lstnew((void*)&new, sizeof(t_room))));
}

static void	remove_room(t_room *del, t_map *map)
{
	t_list	*elem;

	elem = ft_lstat(map->rooms, del->id - 1);
	if (elem->content == (void*)map->start)
		map->start = NULL;
	else if (elem->content == (void*)map->end)
		map->end = NULL;
	elem = elem->next;
	while (elem)
	{
		((t_room*)(elem->content))->id--;
		elem = elem->next;
	}
	ft_lstdel_n(&map->rooms, del->id - 1, &lstdel_room);
}

static void	remove_related_links(t_env *e, t_room *del)
{
	t_list	*tmp;
	t_room	*dep;

	while (del->links)
	{
		dep = (del == ((t_link*)(del->links->content))->a ?
				((t_link*)(del->links->content))->b
				: ((t_link*)(del->links->content))->a);
		remove_link_dep(&dep->links, ((t_link*)(del->links->content))->id);
		e->scene.nb_links--;
		tmp = del->links;
		del->links = del->links->next;
		ft_lstdel_n(&e->map.links, ((t_link*)(tmp->content))->id - 1,
							lstdel_link);
		free_pro((void**)&tmp);
	}
	refresh_all_links(&e->scene, e->map);
}

void		ms_room(void *e, int type, int x, int y)
{
	t_room		*del;
	t_env		*env;
	int			id;

	env = (t_env*)e;
	if (type == SDL_MOUSEBUTTONDOWN && !env->controls.attached.room)
	{
		if ((del = find_closest_room(env->map.rooms,
					(t_vec2){(float)x, (float)y})))
		{
			id = del->id;
			remove_related_links(env, del);
			remove_room(del, &env->map);
			env->scene.nb_rooms--;
			refresh_rooms_from(&env->scene, env->map, id);
		}
		else if (env->scene.nb_rooms < E_ROOM_MAX)
		{
			env->scene.nb_rooms++;
			add_room((t_vec2){(float)x, (float)y}, env->scene.nb_rooms,
												&env->map.rooms);
			refresh_room(&env->scene, env->map, env->scene.nb_rooms);
		}
	}
}
