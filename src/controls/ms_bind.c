#include "controls.h"
#include "visu.h"

void	ms_bind(void *e, int type, int x, int y)
{
	t_env		*env;

	env = (t_env*)e;
	if (type == SDL_MOUSEBUTTONDOWN && SDL_GetModState() & KMOD_CTRL)
	{
		if ((env->controls.attached.room = find_closest_room(env->map.rooms,
								(t_vec2){(float)x, (float)y})))
			env->controls.which = MS_A_ROOM;
	}
	else
	{
		env->controls.attached.room = NULL;
		env->controls.which = MS_A_NONE;
	}
}
