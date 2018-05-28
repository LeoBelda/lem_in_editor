/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:12:58 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 13:55:48 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

static void	search_kb_lookup(t_env *e, SDL_Keycode sym, int type)
{
	int	i;

	i = -1;
	while (++i < KB_MAX)
	{
		if (e->controls.kb_lookup[i].sym == sym)
		{
			e->controls.kb_lookup[i].func(e, type);
			break ;
		}
	}
}

static void	search_ms_lookup(t_env *e, SDL_MouseButtonEvent ms)
{
	int	i;

	i = -1;
	while (++i < MS_MAX)
	{
		if (e->controls.ms_lookup[i].button == ms.button)
		{
			e->controls.ms_lookup[i].func(e, ms.type, ms.x, ms.y);
			break ;
		}
	}
}

void		handle_events(t_env *e)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
			search_kb_lookup(e, event.key.keysym.sym, event.type);
		else if (event.type == SDL_MOUSEBUTTONDOWN ||
				event.type == SDL_MOUSEBUTTONUP)
			search_ms_lookup(e, event.button);
		else if (event.type == SDL_MOUSEMOTION)
			ms_move(e, event.motion);
	}
}
