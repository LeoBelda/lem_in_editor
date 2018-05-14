#ifndef MATRICES_H
# define MATRICES_H

# include "libftmath.h"

typedef struct	s_matrices
{
	t_vec4	eye;
	t_vec4	tar;
	t_vec4	up;
	t_mat4	model_scale;
	t_mat4	view_mat;
	t_mat4	proj_mat;
	t_mat4	final_mat;
}				t_matrices;

#endif