/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 03:57:49 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 11:12:00 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ms_move(void *e, SDL_MouseMotionEvent motion)
{
	t_env		*env;

	env = (t_env*)e;
	if ((motion.state & SDL_BUTTON_LMASK) && env->controls.which == MS_A_ROOM)
	{
		env->controls.attached.room->coords = (t_vec2){(float)motion.x,
													(float)motion.y};
		refresh_room(&env->scene, env->map, env->controls.attached.room->id);
		refresh_related_links(&env->scene, env->map,
				env->controls.attached.room->links);
	}
	else if ((motion.state & SDL_BUTTON_LMASK) &&
							env->controls.which == MS_A_LINK)
	{
		refresh_link(&env->scene, env->map, env->controls.attached.link->id,
							(t_vec2){(float)motion.x, (float)motion.y});
	}
}
