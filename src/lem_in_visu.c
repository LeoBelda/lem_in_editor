#include "visu.h"
#include "parse.h"

void	lem_in_visu(void)
{
	t_env	e;
	t_parse	p;

	p = parse();
	(void)p;
	init_context(&e);
}
