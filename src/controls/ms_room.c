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

void	ms_room(void *e, int type, int x, int y)
{
	t_room		*del;
	t_env		*env;
	static int	i = 1;
	int			id;

	env = (t_env*)e;
	if (type == SDL_MOUSEBUTTONDOWN && !env->controls.attached.room)
	{
		if ((del = find_closest_room(env->map.rooms,
					(t_vec2){(float)x, (float)y})))
		{
			id = del->id;
			remove_room(del, &env->map.rooms);
			env->scene.nb_rooms--;
			refresh_rooms_from(&env->scene, env->map, id);
			i--;
		}
		else
		{
			add_room((t_vec2){(float)x, (float)y}, i, &env->map.rooms);
			env->scene.nb_rooms++;
			refresh_room(&env->scene, env->map, i);
			i++;
		}
	}
}
