/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_startend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:05:23 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 15:43:54 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

void	kb_start(void *e, int type)
{
	t_env	*env;
	t_room	*closest;
	int		x;
	int		y;

	env = (t_env*)e;
	SDL_GetMouseState(&x, &y);
	if (type == SDL_KEYDOWN)
	{
		if ((closest = find_closest_room(env->map.rooms,
							(t_vec2){(float)x, (float)y})))
			env->map.start = closest;
	}
}

void	kb_end(void *e, int type)
{
	t_env	*env;
	t_room	*closest;
	int		x;
	int		y;

	env = (t_env*)e;
	SDL_GetMouseState(&x, &y);
	if (type == SDL_KEYDOWN)
	{
		if ((closest = find_closest_room(env->map.rooms,
							(t_vec2){(float)x, (float)y})))
			env->map.end = closest;
	}
}
