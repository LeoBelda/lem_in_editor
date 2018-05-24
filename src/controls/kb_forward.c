/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_forward.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:29:48 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 10:29:49 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

void	kb_forward(void *e, int type)
{
	((t_env*)e)->scene.timeline.inc = (type == SDL_KEYDOWN ?
				TM_INC : 0.);
}

void	kb_backward(void *e, int type)
{
	((t_env*)e)->scene.timeline.inc = (type == SDL_KEYDOWN ?
				-TM_INC : 0.);
}
