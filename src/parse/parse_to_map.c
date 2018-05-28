/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:17:53 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/28 16:30:10 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "map.h"

static void		check_if_complete(int *ant_state, uintmax_t ant_count)
{
	uintmax_t	i;

	i = 0;
	while (++i < ant_count + 1)
	{
		if (ant_state[i] != -1)
			error_exit("incomplete solution");
	}
}

static t_link	*find_link(t_room end, t_room start)
{
	t_link	*handle;

	while (end.links)
	{
		handle = (t_link*)end.links->content;
		if ((handle->a->id == start.id || handle->b->id == start.id)
				&& (handle->a->id == end.id || handle->b->id == end.id))
			return (handle);
		end.links = end.links->next;
	}
	return (NULL);
}

static t_move	convert_move(t_moveparse old_fmt, t_parse parse,
									int *ants_state)
{
	t_move	move;

	if (ants_state[old_fmt.ant_id] == -1)
		error_exit("illegal move: invalid ant id");
	else
		move.start = (t_room*)(ft_lstat(parse.rooms,
						ants_state[old_fmt.ant_id])->content);
	while (parse.rooms)
	{
		if (!ft_strcmp(((t_room*)parse.rooms->content)->name, old_fmt.name))
		{
			move.end = (t_room*)parse.rooms->content;
			ants_state[old_fmt.ant_id] = (move.end == parse.end ? -1
								: ((t_room*)parse.rooms->content)->id);
			if (!(move.lk = find_link(*move.end, *move.start)))
				error_exit("illegal move: invalid ant dest");
		}
		parse.rooms = parse.rooms->next;
	}
	return (move);
}

t_map			parse_to_map(t_parse parse)
{
	t_map	map;
	int		*ants_state;
	int		i;
	int		j;

	m_pro_null(ants_state = ft_memalloc((parse.ant_count + 1) * sizeof(int)));
	ft_intset(ants_state, parse.start->id, parse.ant_count + 1);
	map = (t_map){ft_lstcount(parse.rooms), ft_lstcount(parse.links),
			ft_lstcount(parse.turns), parse.rooms, parse.links, NULL,
						parse.start, parse.end};
	m_pro_null(map.turns = ft_memalloc((map.nb_turns + 1) * sizeof(t_move*)));
	j = -1;
	while (++j < map.nb_turns)
	{
		m_pro_null(map.turns[j] = ft_memalloc((parse.turns->content_size + 1) *
												sizeof(t_move)));
		i = -1;
		while (((t_moveparse*)parse.turns->content)[++i].name)
			map.turns[j][i] = convert_move(
			((t_moveparse*)parse.turns->content)[i], parse, ants_state);
		parse.turns = parse.turns->next;
	}
	check_if_complete(ants_state, parse.ant_count);
	free_pro((void**)&ants_state);
	return (map);
}
