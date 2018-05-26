#include "libftmath.h"

float	vec2_distance(t_vec2 a, t_vec2 b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}
