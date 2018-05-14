#include "ogl_utils.h"
#include "debug.h"
#include "visu.h"

#define LIM_MIN 0
#define LIM_MAX 1

static void	get_limits(t_map map, t_vec2 *limits)
{
	t_room	*ptr;

	if (map.rooms)
	{
		ptr = (t_room*)map.rooms->content;
		limits[LIM_MIN] = (t_vec2){ptr->coords.x, ptr->coords.y};
		limits[LIM_MAX] = (t_vec2){ptr->coords.x, ptr->coords.y};
	}
	while (map.rooms)
	{
		ptr = (t_room*)map.rooms->content;
		limits[LIM_MIN].x = ft_min(limits[LIM_MIN].x, ptr->coords.x);
		limits[LIM_MIN].y = ft_min(limits[LIM_MIN].y, ptr->coords.y);
		limits[LIM_MAX].x = ft_max(limits[LIM_MAX].x, ptr->coords.x);
		limits[LIM_MAX].y = ft_max(limits[LIM_MAX].y, ptr->coords.y);
		map.rooms = map.rooms->next;
	}
}

t_matrices	init_matrices(t_map map, float ratio)
{
	t_matrices	matrices;
	t_vec2		lim[2];

	(void)ratio;
	get_limits(map, lim);
	matrices.eye = (t_vec4){(lim[LIM_MIN].x + lim[LIM_MAX].x) / -2.,
						(lim[LIM_MIN].y + lim[LIM_MAX].y) / -2., 10., 1.};
	matrices.tar = (t_vec4){(lim[LIM_MIN].x + lim[LIM_MAX].x) / -2.,
						(lim[LIM_MIN].y + lim[LIM_MAX].y) / -2., 0., 1.};
	matrices.up = (t_vec4){0., 1., 0., 0.};
	matrices.model_scale = sclmat4new(0.2, 0.2, 0.2);
	matrices.view_mat = look_at(matrices.eye, matrices.tar, matrices.up);
	//matrices.proj_mat = orthomat4new(frustrumnew(FR_HEIGTH * ratio,
	//			FR_HEIGTH, 100., -100.));
	matrices.proj_mat = persmat4new(110., 78., 1000., 1.0);
	matrices.final_mat = mat4xmat4(matrices.proj_mat, matrices.view_mat);
	return (matrices);
}
