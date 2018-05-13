#ifndef T_MAP
# define T_MAP

# include "libft.h"
# include "printf.h"
# include "objects.h"

typedef struct	s_move
{
	t_room	*start;
	t_room	*end;
	t_link	*lk;
}				t_move;

typedef struct	s_map
{
	int		nb_rooms;
	t_list	*rooms;
	t_list	*links;
	t_list	*turns;
	t_room	*start;
	t_room	*end;
}				t_map;

#endif
