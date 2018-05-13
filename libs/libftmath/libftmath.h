/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:18:55 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/16 12:18:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATH_H
# define LIBFTMATH_H

# include <math.h>
# include <unistd.h>

# define MSK(x) ((x) & 0x000000ff)

# ifndef T_VEC2R
#  define T_VEC2R

typedef struct	s_vec2r
{
	int	x;
	int	y;
}				t_vec2r;

# endif

typedef struct	s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec4;

typedef struct	s_mat4
{
	t_vec4	x;
	t_vec4	y;
	t_vec4	z;
	t_vec4	w;
}				t_mat4;

typedef struct	s_frustrum
{
	float	r;
	float	l;
	float	t;
	float	b;
	float	f;
	float	n;
}				t_frustrum;

t_mat4			mat4_interi(t_mat4 mat1, t_mat4 mat2,
								int distance, int progress);
float			dbl_interr(float a, float b, float ratio);
float			dbl_interr_log(float a, float b, float ratio);

t_vec2r			vec2rnewd(float x, float y);
t_vec2r			vec2rnewi(int x, int y);
t_vec4			vec4new(float x, float y, float z, float w);
t_vec4			vec4neg(t_vec4 vec);
t_mat4			mat4new(t_vec4 x, t_vec4 y, t_vec4 z, t_vec4 w);
t_mat4			mat4inv(t_mat4 a);
t_mat4			idmat4new(void);
t_mat4			sclmat4new(float x, float y, float z);
t_mat4			trsmat4new(float x, float y, float z);
t_mat4			trsmat4vec(t_vec4 vec);
t_mat4			rotxmat4new(float x);
t_mat4			rotymat4new(float y);
t_mat4			rotzmat4new(float z);
t_mat4			orthomat4new(t_frustrum fr);
t_mat4			persmat4new(float fovh, float fovl, float f, float n);
t_frustrum		frustrumnew(float r, float t, float f, float n);
t_mat4			look_at(t_vec4 eye, t_vec4 target, t_vec4 up);

t_vec4			cross_product(t_vec4 a, t_vec4 b);
float			dot_product(t_vec4 a, t_vec4 b);
t_vec4			norm_vec4(t_vec4 vec);
float			vec4_xy_distance(t_vec4 a, t_vec4 b);
float			vec4_xz_distance(t_vec4 a, t_vec4 b);
float			vec4xvec4(t_vec4 a, t_vec4 b);
t_vec4			mat4xvec4(t_mat4 mat, t_vec4 vec);
t_vec4			vec4xmat4(t_vec4 vec, t_mat4 mat);
t_mat4			mat4xmat4(t_mat4 a, t_mat4 b);
t_vec3			mat4xvec4_tovec3(t_mat4 mat, t_vec4 vec);

float			deg_rad(float deg);
int				iabs(int val);
int				imod(int a, int b);
float			clamp(float val, float min, float max);

#endif
