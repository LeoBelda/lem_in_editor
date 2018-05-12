/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:28:10 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/07 16:28:10 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4			look_at(t_vec4 eye, t_vec4 target, t_vec4 up)
{
	t_vec4	x_vec;
	t_vec4	y_vec;
	t_vec4	z_vec;

	z_vec = norm_vec4(
			vec4new(target.x - eye.x, target.y - eye.y,
					target.z - eye.z, 0.0));
	x_vec = cross_product(z_vec, norm_vec4(up));
	y_vec = cross_product(x_vec, z_vec);
	return (mat4new(vec4new(x_vec.x, y_vec.x, -z_vec.x, 0.0),
					vec4new(x_vec.y, y_vec.y, -z_vec.y, 0.0),
					vec4new(x_vec.z, y_vec.z, -z_vec.z, 0.0),
					vec4new(dot_product(x_vec, eye),
							dot_product(y_vec, eye),
							dot_product(z_vec, eye), 1.0)));
}
