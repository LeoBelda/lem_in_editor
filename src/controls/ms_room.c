#include "controls.h"
#include "visu.h"

static void	add_room(t_vec2 coords, int id, t_list **rooms)
{
	t_room		new;

	new = (t_room){id, ft_itoa(id), coords, NULL};
	m_pro(ft_lstradd(rooms, ft_lstnew((void*)&new, sizeof(t_room))));
}

static void	remove_room(t_room *del, t_list **rooms)
{
	t_list	*elem;

	elem = ft_lstat(*rooms, del->id - 1)->next;
	while (elem)
	{
		((t_room*)(elem->content))->id--;
		elem = elem->next;
	}
	ft_lstdel_n(rooms, del->id - 1, &lstdel_room);
}

static void	remove_link_dep(t_list **links, int id)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *links;
	while (tmp)
	{
		if (id == ((t_link*)(tmp->content))->id)
			break;
		tmp = tmp->next;
		i++;
	}
	ft_lstdel_n(links, i, lstdel_link);
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
		ft_lstdel_n(&e->map.links, ((t_link*)(del->links->content))->id - 1,
							lstdel_link);
		e->scene.nb_links--;
		tmp = del->links;
		del->links = del->links->next;
		free_pro((void**)&tmp);
	}
	refresh_all_links(&e->scene, e->map);
}

void	ms_room(void *e, int type, int x, int y)
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
			remove_room(del, &env->map.rooms);
			env->scene.nb_rooms--;
			refresh_rooms_from(&env->scene, env->map, id);
		}
		else
		{
			env->scene.nb_rooms++;
			add_room((t_vec2){(float)x, (float)y}, env->scene.nb_rooms,
												&env->map.rooms);
			refresh_room(&env->scene, env->map, env->scene.nb_rooms);
		}
	}
}
