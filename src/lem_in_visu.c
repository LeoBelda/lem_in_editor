#include "visu.h"
#include "map.h"
#include "parse.h"

void	lem_in_visu(void)
{
	t_env	e;
	t_parse	p;

	p = parse();
	e.map = parse_to_map(p);
	clean_parse(p);
	init_context(&e);
}
