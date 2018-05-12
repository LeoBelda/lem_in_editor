#ifndef PARSE_H
# define PARSE_H

# include "common.h"
# include "libft.h"

enum			e_parse_funcs
{
	PARSE_ANTS,
	PARSE_ROOM,
	PARSE_LINK,
	PARSE_MAX
};

typedef enum	e_command
{
	COMMAND_START,
	COMMAND_END,
	COMMAND_NONE
}				t_command;

typedef struct	s_room
{
	char			*name;
	t_vec2			coords;
	t_list			*links;
}				t_room;

typedef struct	s_parse
{
	int			(*p_funcs[PARSE_MAX])(const char*, struct s_parse*);
	int			parse_state;
	uintmax_t	ant_count;
	t_command	command;
	t_room		*start;
	t_room		*end;
	t_list		*rooms;
}				t_parse;

t_parse			parse(void);

#endif
