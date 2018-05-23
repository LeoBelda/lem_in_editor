#include "controls.h"
#include "visu.h"

void	kb_play(void *e, int type)
{
	if (type == SDL_KEYDOWN)
		((t_env*)e)->scene.timeline.inc =
			(((t_env*)e)->scene.timeline.inc == TM_INC ? 0 : TM_INC);
}
