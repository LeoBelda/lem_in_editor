/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 03:57:49 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/25 17:58:58 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ms_create(void *e, int type, int x, int y)
{
	t_room		new;
	t_env		*env;
	static int	i = 1;

	env = (t_env*)e;
	if (type == SDL_MOUSEBUTTONDOWN)
	{
		new = (t_room){i, ft_itoa(i), (t_vec2){(float)x, (float)y}, NULL};
		ft_lstradd(&env->map.rooms, ft_lstnew((void*)&new, sizeof(t_room)));
		env->scene.nb_rooms++;
		refresh_rooms(&env->scene, env->map);
		i++;
	}
}

void	ms_grab(void *e, int type, int x, int y)
{
	t_env		*env;

	env = (t_env*)e;
	if (type == SDL_MOUSEBUTTONDOWN)
	{
		env->controls.attached.room = find_closest_room(env->map.rooms,
								(t_vec2){(float)x, (float)y});
	}
	else
	{
		env->controls.attached.room = NULL;
	}
}

void	ms_bound_object(void *e, SDL_MouseMotionEvent motion)
{
	t_env		*env;

	env = (t_env*)e;
	if (motion.state & SDL_BUTTON_LMASK && env->controls.attached.room)
	{
		env->controls.attached.room->coords = (t_vec2){(float)motion.x,
													(float)motion.y};
		refresh_rooms(&env->scene, env->map);
	}
}
