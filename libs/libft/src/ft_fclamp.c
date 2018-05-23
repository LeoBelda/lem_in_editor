#include "libft.h"

float	ft_fmin(float a, float b)
{
	return (a > b ? b : a);
}

float	ft_fmax(float a, float b)
{
	return (a < b ? b : a);
}

float	ft_fclamp(float min, float max, float val)
{
	return (ft_fmax(ft_fmin(max, val), min));
}
