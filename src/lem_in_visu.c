/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:27:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/25 07:51:03 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"
#include "map.h"
#include "parse.h"
#include "scene.h"

void	lem_in_visu(t_mode mode)
{
	t_env		e;
	t_parse		p;

	ft_bzero(&e, sizeof(t_env));
	e.mode = mode;
	if (mode == V_VISU)
	{
		p = parse();
		e.map = parse_to_map(p);
		clean_parse(p);
	}
	e.controls = init_controls(mode);
	init_env(&e);
	e.matrices = init_matrices(e.map, e.ratio,
							(t_vec2){e.x_win, e.y_win}, mode);
	e.scene = (mode == V_VISU ? init_scene(e.map) : init_scene_edit(e.map));
	render(&e);
}
