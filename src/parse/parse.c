/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:30:18 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/29 11:27:52 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	init_p_funcs(int (*f[PARSE_MAX])(const char*, t_parse*))
{
	f[PARSE_ANTS] = &parse_ants;
	f[PARSE_ROOM] = &parse_room;
	f[PARSE_LINK] = &parse_link;
	f[PARSE_MOVES] = &parse_moves;
}

static int	parse_line(char *line, t_parse *parse)
{
	int	i;

	i = ft_skipwhitespace(line);
	if (!line)
		return (LINE_MAP_BAD);
	if (!line[i] && parse->mode == M_MAP)
	{
		parse->mode = M_MOVES;
		parse->parse_state = PARSE_MOVES;
		ft_printf("\n");
		return (LINE_OK);
	}
	else if (!ft_strcmp(line, "ERROR"))
		return (LINE_MAP_BAD);
	else if (line[i] == '#' && parse->mode == M_MAP)
	{
		if (line[i + 1] == '#')
			return (parse_command(&line[i], parse));
		else
			return (parse_comment(&line[i], parse));
	}
	else
		return (parse->p_funcs[parse->parse_state](&line[i], parse));
}

t_parse		parse(void)
{
	char	*line;
	int		ret;
	int		valid_line;
	t_parse	parse;

	line = NULL;
	valid_line = LINE_OK;
	ft_bzero(&parse, sizeof(t_parse));
	init_p_funcs(parse.p_funcs);
	parse.mode = M_MAP;
	while (valid_line == LINE_OK && (ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			error_exit("get_next_line failed");
		valid_line = parse_line(line, &parse);
		free_pro((void**)&line);
		if (valid_line != LINE_OK)
			error_exit(valid_line == LINE_USR_BAD ?
						"solution badly formatted" : "map error");
	}
	ft_lstrev(&parse.links);
	return (parse);
}
