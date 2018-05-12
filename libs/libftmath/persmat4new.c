/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persmat4new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:59:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/30 20:47:41 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	persmat4new(float fovh, float fovl, float f, float n)
{
	t_mat4	pers;

	pers.x = vec4new(1.0 / (tan(deg_rad(fovh / 2.0))), 0.0, 0.0, 0.0);
	pers.y = vec4new(0.0, 1.0 / (tan(deg_rad(fovl / 2.0))), 0.0, 0.0);
	pers.z = vec4new(0.0, 0.0, (n + f) / (n - f), (2. * f * n) / (n - f));
	pers.w = vec4new(0.0, 0.0, -1.0, 0.0);
	return (pers);
}
