/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:27:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 10:27:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"
#include "map.h"
#include "parse.h"
#include "scene.h"

void	lem_in_visu(void)
{
	t_env		e;
	t_parse		p;

	ft_bzero(&e, sizeof(t_env));
	p = parse();
	e.map = parse_to_map(p);
	e.controls = init_controls();
	clean_parse(p);
	init_env(&e);
	e.matrices = init_matrices(e.map, e.ratio);
	e.scene = init_scene(e.map);
	render(&e);
}
