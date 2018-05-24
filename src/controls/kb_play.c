/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:29:57 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 10:29:57 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

void	kb_play(void *e, int type)
{
	if (type == SDL_KEYDOWN)
		((t_env*)e)->scene.timeline.inc =
			(((t_env*)e)->scene.timeline.inc != 0. ? 0 : TM_INC);
}
