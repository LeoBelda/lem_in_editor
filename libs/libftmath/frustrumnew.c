/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frustrumnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:44:52 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 22:56:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_frustrum		ffrustrumnew(t_vec2 lr, t_vec2 bt, t_vec2 fn)
{
	t_frustrum	fr;

	fr.l = lr.x;
	fr.r = lr.y;
	fr.b = bt.x;
	fr.t = bt.y;
	fr.f = fn.x;
	fr.n = fn.y;
	return (fr);
}

t_frustrum		frustrumnew(float r, float t, float f, float n)
{
	t_frustrum	fr;

	fr.r = r;
	fr.t = t;
	fr.f = f;
	fr.n = n;
	return (fr);
}
