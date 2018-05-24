/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:29:20 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 16:36:03 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "objects.h"
# include "libft.h"
# include "common.h"

# define WHITE_STR " \t\v\f\r"
# define DIGIT_STR "-0123456789"

enum			e_parse_funcs
{
	PARSE_ANTS,
	PARSE_ROOM,
	PARSE_LINK,
	PARSE_MOVES,
	PARSE_MAX
};

typedef enum	e_command
{
	COMMAND_NONE,
	COMMAND_START,
	COMMAND_END
}				t_command;

enum			e_parse_mode
{
	M_MAP,
	M_MOVES
};

enum			e_line_validity
{
	LINE_USR_BAD = -1,
	LINE_MAP_BAD,
	LINE_OK
};

typedef struct	s_moveparse
{
	uintmax_t	ant_id;
	char		*name;
}				t_moveparse;

typedef struct	s_parse
{
	int			(*p_funcs[PARSE_MAX])(const char*, struct s_parse*);
	int			mode;
	int			parse_state;
	uintmax_t	ant_count;
	t_command	command;
	t_room		*start;
	t_room		*end;
	t_list		*turns;
	t_list		*rooms;
	t_list		*links;
}				t_parse;

t_parse			parse(void);

int				parse_ants(const char *line, t_parse *parse);
int				parse_room(const char *line, t_parse *parse);
int				parse_link(const char *line, t_parse *parse);
int				parse_moves(const char *line, t_parse *parse);
int				parse_command(const char *line, t_parse *parse);
int				parse_comment(const char *line, t_parse *parse);

void			apply_command(t_parse *parse);
int				link_is_duplicate(t_room *link, t_list *links);
t_room			*look_for_room(const char *name, t_list *rooms);
int				name_is_duplicate(const char *name, t_list *rooms);
t_vec2			get_room_coords(const char *line);

void			clean_parse(t_parse parse);

#endif
