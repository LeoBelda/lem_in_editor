/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:13:03 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 17:29:48 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "map.h"

void	kb_quit(void *e, int type)
{
	if (type == SDL_KEYDOWN)
	{
		if (((t_env*)e)->mode == V_EDIT)
			print_map(((t_env*)e)->map);
		((t_env*)e)->quit = 1;
	}
}

void	kb_debug(void *e, int type)
{
	(void)e;
	(void)type;
}

void	kb_none(void *e, int type)
{
	(void)e;
	(void)type;
}
