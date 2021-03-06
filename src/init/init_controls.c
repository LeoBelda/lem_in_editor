/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:16:07 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 15:04:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"

static t_controls	controls_visu(void)
{
	t_controls	controls;

	controls.kb_lookup[KB_RIGHT] = (t_kb_lookup){SDLK_RIGHT, &kb_forward};
	controls.kb_lookup[KB_LEFT] = (t_kb_lookup){SDLK_LEFT, &kb_backward};
	controls.kb_lookup[KB_DOWN] = (t_kb_lookup){SDLK_DOWN, &kb_none};
	controls.kb_lookup[KB_UP] = (t_kb_lookup){SDLK_UP, &kb_none};
	controls.kb_lookup[KB_D] = (t_kb_lookup){SDLK_d, &kb_none};
	controls.kb_lookup[KB_A] = (t_kb_lookup){SDLK_a, &kb_none};
	controls.kb_lookup[KB_S] = (t_kb_lookup){SDLK_s, &kb_none};
	controls.kb_lookup[KB_W] = (t_kb_lookup){SDLK_w, &kb_none};
	controls.kb_lookup[KB_P] = (t_kb_lookup){SDLK_p, &kb_none};
	controls.kb_lookup[KB_SPACE] = (t_kb_lookup){SDLK_SPACE, &kb_play};
	controls.kb_lookup[KB_ESCAPE] = (t_kb_lookup){SDLK_ESCAPE, &kb_quit};
	return (controls);
}

static t_controls	controls_edit(void)
{
	t_controls controls;

	controls.attached.room = NULL;
	controls.which = MS_A_NONE;
	controls.ms_lookup[MS_RIGHT] = (t_ms_lookup){SDL_BUTTON_RIGHT, &ms_room};
	controls.ms_lookup[MS_LEFT] = (t_ms_lookup){SDL_BUTTON_LEFT, &ms_bind};
	controls.kb_lookup[KB_S] = (t_kb_lookup){SDLK_s, &kb_start};
	controls.kb_lookup[KB_E] = (t_kb_lookup){SDLK_e, &kb_end};
	controls.kb_lookup[KB_ESCAPE] = (t_kb_lookup){SDLK_ESCAPE, &kb_quit};
	return (controls);
}

t_controls			init_controls(t_mode mode)
{
	return (mode == V_VISU ? controls_visu() : controls_edit());
}
