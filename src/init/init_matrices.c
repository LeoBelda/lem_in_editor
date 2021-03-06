/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:27:28 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 13:55:14 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ogl_utils.h"
#include "debug.h"
#include "visu.h"

#define VOID_RATIO 0.20

#define SCALE 0.013

#define LIM_MIN 0
#define LIM_MAX 1
#define LIM_MIN_FR 2
#define LIM_MAX_FR 3

static void	get_limits(t_map map, t_vec2 *limits)
{
	t_room	*ptr;

	if (map.rooms)
	{
		ptr = (t_room*)map.rooms->content;
		limits[LIM_MIN] = (t_vec2){ptr->coords.x, ptr->coords.y};
		limits[LIM_MAX] = (t_vec2){ptr->coords.x, ptr->coords.y};
	}
	while (map.rooms)
	{
		ptr = (t_room*)map.rooms->content;
		limits[LIM_MIN].x = ft_min(limits[LIM_MIN].x, ptr->coords.x);
		limits[LIM_MIN].y = ft_min(limits[LIM_MIN].y, ptr->coords.y);
		limits[LIM_MAX].x = ft_max(limits[LIM_MAX].x, ptr->coords.x);
		limits[LIM_MAX].y = ft_max(limits[LIM_MAX].y, ptr->coords.y);
		map.rooms = map.rooms->next;
	}
}

static void	get_frustrum_bounds(t_vec2 *limits, float ratio)
{
	float	mid;
	float	dst;

	if (limits[LIM_MAX].x - limits[LIM_MIN].x <
			(limits[LIM_MAX].y - limits[LIM_MIN].y) * ratio)
	{
		mid = (limits[LIM_MAX].x + limits[LIM_MIN].x) / 2.;
		dst = (limits[LIM_MAX].y - limits[LIM_MIN].y) / 2.;
		limits[LIM_MIN].y -= (VOID_RATIO * dst);
		limits[LIM_MAX].y += (VOID_RATIO * dst);
		dst = (limits[LIM_MAX].y - limits[LIM_MIN].y) / 2.;
		limits[LIM_MIN].x = mid - dst * ratio;
		limits[LIM_MAX].x = mid + dst * ratio;
	}
	else
	{
		mid = (limits[LIM_MAX].y + limits[LIM_MIN].y) / 2.;
		dst = (limits[LIM_MAX].x - limits[LIM_MIN].x) / 2.;
		limits[LIM_MIN].x -= (VOID_RATIO * dst);
		limits[LIM_MAX].x += (VOID_RATIO * dst);
		dst = (limits[LIM_MAX].x - limits[LIM_MIN].x) / 2.;
		limits[LIM_MIN].y = mid - dst / ratio;
		limits[LIM_MAX].y = mid + dst / ratio;
	}
}

t_matrices	init_matrices(t_map map, float ratio, t_vec2 win, t_mode mode)
{
	t_matrices	matrices;
	t_vec2		lim[2];

	if (mode == V_VISU)
	{
		get_limits(map, lim);
		get_frustrum_bounds(lim, ratio);
	}
	else
	{
		lim[LIM_MIN] = (t_vec2){0., 0.};
		lim[LIM_MAX] = (t_vec2){win.x, win.y};
	}
	matrices.eye = (t_vec4){(lim[LIM_MIN].x + lim[LIM_MAX].x) / -2.,
						(lim[LIM_MIN].y + lim[LIM_MAX].y) / -2., 10., 1.};
	matrices.tar = (t_vec4){(lim[LIM_MIN].x + lim[LIM_MAX].x) / -2.,
						(lim[LIM_MIN].y + lim[LIM_MAX].y) / -2., 0., 1.};
	matrices.up = (t_vec4){0., 1., 0., 0.};
	matrices.model_scale = (lim[LIM_MAX].x - lim[LIM_MIN].x) * SCALE;
	matrices.view_mat = look_at(matrices.eye, matrices.tar, matrices.up);
	matrices.proj_mat = orthomat4new(ffrustrumnew(
		(t_vec2){lim[LIM_MIN].x, lim[LIM_MAX].x},
		(t_vec2){lim[LIM_MAX].y, lim[LIM_MIN].y}, (t_vec2){100., -100.}));
	matrices.final_mat = mat4xmat4(matrices.proj_mat, matrices.view_mat);
	return (matrices);
}
