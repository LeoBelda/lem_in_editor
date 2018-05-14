#include "parse.h"

static void	lstdel_moveparse(void *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free_pro((void**)&(((t_moveparse*)content)[i].name));
		i++;
	}
	free_pro((void**)&content);
}

void	clean_parse(t_parse parse)
{
	ft_lstdel(&parse.turns, &lstdel_moveparse);
}
