/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:07:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/05/24 13:07:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "debug.h"

void	print_vec2(t_glfloat2 vec)
{
	ft_printf("x:%f y:%f\n", vec.x, vec.y);
}

void	print_mat4(t_mat4 mat)
{
	ft_printf("x:%f y:%f z:%f w:%f\n", mat.x.x, mat.x.y, mat.x.z, mat.x.w);
	ft_printf("x:%f y:%f z:%f w:%f\n", mat.y.x, mat.y.y, mat.y.z, mat.y.w);
	ft_printf("x:%f y:%f z:%f w:%f\n", mat.z.x, mat.z.y, mat.z.z, mat.z.w);
	ft_printf("x:%f y:%f z:%f w:%f\n", mat.w.x, mat.w.y, mat.w.z, mat.w.w);
	ft_printf("\n");
}
