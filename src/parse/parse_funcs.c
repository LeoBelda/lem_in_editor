/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:23:35 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/31 10:53:24 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#define L1 0
#define L2 1

int			parse_ants(const char *line, t_parse *parse)
{
	int	i;

	i = 0;
	if (line[i] == '+')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	while (ft_iswhitespace(line[i]))
		i++;
	if (line[i])
		return (LINE_MAP_BAD);
	parse->ant_count = ft_atoui(line);
	parse->parse_state = PARSE_ROOM;
	if (!parse->ant_count)
		return (LINE_MAP_BAD);
	ft_putendl(line);
	return (LINE_OK);
}

static int	line_is_room(const char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'L')
		return (LINE_MAP_BAD);
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	if (!i || !ft_iswhitespace(line[i]))
		return (LINE_MAP_BAD);
	i += ft_skipwhitespace(&line[i]);
	i += (line[i] == '-' ? 1 : 0);
	if (!ft_isdigit(line[i]))
		return (LINE_MAP_BAD);
	while (ft_isdigit(line[i]))
		i++;
	if (!i || !ft_iswhitespace(line[i]))
		return (LINE_MAP_BAD);
	i += ft_skipwhitespace(&line[i]);
	i += (line[i] == '-' ? 1 : 0);
	while (ft_isdigit(line[i]))
		i++;
	i += ft_skipwhitespace(&line[i]);
	if (line[i])
		return (LINE_MAP_BAD);
	return (LINE_OK);
}

static int	store_link(const char *line, t_parse *parse, int len1, int len2)
{
	char		r1[len1 + 1];
	char		r2[len2 + 1];
	t_room		*p[2];
	static int	id = 0;
	t_link		link;

	ft_strncpy(r1, line, len1);
	r1[len1] = '\0';
	ft_strncpy(r2, &line[ft_strcspn(line, "-") + 1], len2);
	r2[len2] = '\0';
	if (!ft_strcmp(r1, r2) || !(p[L1] = look_for_room(r1, parse->rooms))
							|| !(p[L2] = look_for_room(r2, parse->rooms)))
		return (LINE_MAP_BAD);
	if (!link_is_duplicate(p[L1], p[L2]->p_links))
	{
		link = (t_link){id, p[L1], p[L2]};
		m_pro(ft_lstadd(&parse->links,
					ft_lstnew((void*)&link, sizeof(t_link))));
		m_pro(ft_lstadd(&p[L1]->links, ft_lstnewref(parse->links->content, 0)));
		m_pro(ft_lstadd(&p[L2]->links, ft_lstnewref(parse->links->content, 0)));
		m_pro(ft_lstadd(&p[L1]->p_links, ft_lstnewref(p[L2], 0)));
		m_pro(ft_lstadd(&(p[L2]->p_links), ft_lstnewref(p[L1], 0)));
		id++;
	}
	return (LINE_OK);
}

int			parse_room(const char *line, t_parse *parse)
{
	int			i;
	static int	id = 0;
	char		*name;
	t_vec2		xy;

	if (parse_link(line, parse))
	{
		parse->parse_state = PARSE_LINK;
		return (LINE_OK);
	}
	if (!line_is_room(line))
		return (LINE_MAP_BAD);
	m_pro_null(name = ft_strndup(line, ft_strcspn(line, WHITE_STR)));
	if (name_is_duplicate(name, parse->rooms))
	{
		free_pro((void**)&name);
		return (LINE_MAP_BAD);
	}
	i = ft_strlen(name);
	xy = get_room_coords(&line[i]);
	m_pro(ft_lstradd(&parse->rooms,
		ft_lstnew(&((t_room){id++, name, xy, NULL, NULL}), sizeof(t_room))));
	ft_putendl(line);
	parse->command != COMMAND_NONE ? apply_command(parse) : (void)parse;
	return (LINE_OK);
}

int			parse_link(const char *line, t_parse *parse)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	len1 = i;
	if (!i || line[i++] != '-')
		return (LINE_MAP_BAD);
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	len2 = i - len1 - 1;
	i += ft_skipwhitespace(&line[i]);
	if (line[i])
		return (LINE_MAP_BAD);
	ft_putendl(line);
	return (store_link(line, parse, len1, len2));
}
