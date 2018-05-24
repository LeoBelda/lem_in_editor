/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:24:08 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 13:15:02 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		name_is_duplicate(const char *name, t_list *rooms)
{
	while (rooms)
	{
		if (!ft_strcmp(name, ((t_room*)rooms->content)->name))
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

t_room	*look_for_room(const char *name, t_list *rooms)
{
	while (rooms)
	{
		if (!ft_strcmp(name, ((t_room*)rooms->content)->name))
			return ((t_room*)rooms->content);
		rooms = rooms->next;
	}
	return (NULL);
}

int		link_is_duplicate(t_room *link, t_list *links)
{
	while (links)
	{
		if (links->content == (void*)link)
			return (1);
		links = links->next;
	}
	return (0);
}

void	apply_command(t_parse *parse)
{
	if (parse->command == COMMAND_START)
		parse->start = (t_room*)parse->rooms->content;
	else if (parse->command == COMMAND_END)
		parse->end = (t_room*)parse->rooms->content;
	parse->command = COMMAND_NONE;
}

t_vec2	get_room_coords(const char *line)
{
	int		i;
	t_vec2	coords;

	i = 0;
	i += ft_skipwhitespace(&line[i]);
	coords.x = (float)ft_atoi(&line[i]);
	i += ft_strspn(&line[i], DIGIT_STR);
	i += ft_strspn(&line[i], WHITE_STR);
	coords.y = (float)ft_atoi(&line[i]);
	return (coords);
}
