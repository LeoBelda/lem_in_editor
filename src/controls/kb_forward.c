#include "controls.h"
#include "visu.h"

void	kb_forward(void *e, int type)
{
	((t_env*)e)->scene.timeline.inc = (type == SDL_KEYDOWN ?
				TM_INC : 0.);
}

void	kb_backward(void *e, int type)
{
	((t_env*)e)->scene.timeline.inc = (type == SDL_KEYDOWN ?
				-TM_INC : 0.);
}
