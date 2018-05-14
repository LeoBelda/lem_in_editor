#include "parse.h"

void	lstdel_moveparse(void *content, size_t size)
{
	(void)size;
	free_pro((void**)&(((t_moveparse*)content)->name));
}
