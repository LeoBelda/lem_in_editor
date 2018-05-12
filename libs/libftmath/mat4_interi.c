/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_interi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:44:59 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 19:00:25 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_mat4	mat4_interi(t_mat4 mat1, t_mat4 mat2, int distance, int progress)
{
	t_mat4	inter;
	int		ratio;
	size_t	j;

	if (distance == 0)
		return (mat1);
	ratio = progress * 100 / distance;
	j = 0;
	while (&(((float*)(&inter))[j]) <= &(inter.w.w))
	{
		((float*)(&inter))[j] = dbl_interr(((float*)(&mat1))[j],
							((float*)(&mat2))[j], (float)ratio);
		j++;
	}
	return (inter);
}
