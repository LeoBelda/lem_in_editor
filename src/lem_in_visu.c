/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:27:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/31 10:37:05 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "visu.h"
#include "map.h"
#include "parse.h"
#include "scene.h"

static uintmax_t	prompt_user(void)
{
	char		*line;
	uintmax_t	ants;
	int			ret;

	line = NULL;
	ft_dprintf(2, "CONTROLS\n"
		"Mouse Right-click                     :    create/delete room\n"
		"Mouse Left-click (hold)               :    draw link\n"
		"CTRL (hold) + Mouse Left-click (hold) :    move\n"
		"Press S while cursor over a room      :    start room\n"
		"      E                               :    end room\n"
		"      ESC                             :    quit and print map\n\n"
		"Enter ants number :\n");
	ret = get_next_line(0, &line);
	if (ret == -1)
		error_exit("get next line failed");
	ants = ft_atoui(line);
	if (ants <= 0)
		error_exit("invalid ant count");
	return (ants);
}

void				lem_in_visu(t_mode mode)
{
	t_env		e;
	t_parse		p;

	ft_bzero(&e, sizeof(t_env));
	e.mode = mode;
	if (mode == V_VISU)
	{
		p = parse();
		if (p.start && p.end)
			e.map = parse_to_map(p);
		else
			error_map(p, "map error: missing start or end");
		clean_parse(p);
	}
	else
		e.map.nb_ants = prompt_user();
	e.controls = init_controls(mode);
	init_env(&e);
	e.matrices = init_matrices(e.map, e.ratio,
							(t_vec2){e.x_win, e.y_win}, mode);
	e.scene = (mode == V_VISU ? init_scene(e.map) : init_scene_edit(e.map));
	render(&e);
	clean_env(&e);
}
