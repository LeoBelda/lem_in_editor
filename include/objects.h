#ifndef T_OBJECTS
# define T_OBJECTS

# include "libftmath.h"
# include "libft.h"

typedef struct	s_room
{
	int				id;
	char			*name;
	t_vec2			coords;
	t_list			*links;
}				t_room;

typedef struct	s_link
{
	t_room	*a;
	t_room	*b;
}				t_link;

#endif
