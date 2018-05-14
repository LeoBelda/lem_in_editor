/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:12:58 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/02 14:49:16 by lbelda           ###   ########.fr       */
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

void		handle_events(t_env *e)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
			search_kb_lookup(e, event.key.keysym.sym, event.type);
	}
}
