#include "controls.h"
#include "visu.h"
#include "map.h"
#include "parse.h"

void	lem_in_visu(void)
{
	t_env		e;
	t_parse		p;

	ft_bzero(&e, sizeof(t_env));
	p = parse();
	e.map = parse_to_map(p);
	e.controls = init_controls();
	clean_parse(p);
	init_env(&e);
	render(&e);
}
