#include "parse.h"
#include "map.h"

static t_link	*find_link(t_room *end, t_list *links)
{
	t_link	*handle;

	while (links)
	{
		handle = (t_link*)links->content;
		if (handle->a == end || handle->b == end)
			return (handle);
		links = links->next;
	}
	return (NULL);
}

static t_move	convert_move(t_moveparse old_fmt, t_parse parse, int *ants_state)
{
	t_move	move;

	if (!ants_state[old_fmt.ant_id])
		move.start = parse.start;
	else if (ants_state[old_fmt.ant_id] == -1)
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
			if (!(move.lk = find_link(move.end,
							((t_room*)parse.rooms->content)->links)))
				error_exit("illegal move: invalid ant dest");
		}
		parse.rooms = parse.rooms->next;
	}
	return (move);
}

t_map		parse_to_map(t_parse parse)
{
	t_map	map;
	t_move	*moves;
	int		*ants_state;
	int		i;

	m_pro_null(ants_state = ft_memalloc((parse.ant_count + 1) * sizeof(int)));
	map = (t_map){ft_lstcount(parse.rooms), ft_lstcount(parse.links),
						parse.rooms, parse.links, NULL,
						parse.start, parse.end};
	while (parse.turns)
	{
		m_pro_null(moves = ft_memalloc(parse.turns->content_size *
												sizeof(t_move)));
		i = -1;
		while (((t_moveparse*)parse.turns->content)[++i].name)
			moves[i] = convert_move(((t_moveparse*)parse.turns->content)[i],
									parse, ants_state);
		m_pro(ft_lstadd(&map.turns,
					ft_lstnewref((void*)moves, parse.turns->content_size)));
		parse.turns = parse.turns->next;
	}
	free_pro((void**)&ants_state);
	return (map);
}
