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

void	ms_move(void *e, SDL_MouseMotionEvent motion)
{
	t_env		*env;

	env = (t_env*)e;
	if ((motion.state & SDL_BUTTON_LMASK) && env->controls.attached.room)
	{
		env->controls.attached.room->coords = (t_vec2){(float)motion.x,
													(float)motion.y};
		ft_putendl("brooo");
		refresh_room(&env->scene, env->map, env->controls.attached.room->id);
	}
}
