/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:24:21 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/17 10:10:02 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define M_SIGN 0x8000000000000000
#define M_EXP 0x7FF0000000000000
#define M_MAN 0x000FFFFFFFFFFFFF
#define M_LAST 0x0010000000000000

#define SHIFT_EXP 52
#define OFFSET_EXP 1023
#define SUB_EXP -1022

static t_dspe	check_spe(t_dcomp d)
{
	if (d.exp == (M_EXP >> SHIFT_EXP))
		return (d.man ? DS_NAN : DS_INF);
	else if (!d.exp)
		return (d.man ? DS_SUB : DS_ZERO);
	else
		return (DS_NORMAL);
}

static void		redress_man(t_dcomp *d)
{
	if (d->man)
		while (!(d->man & M_LAST))
		{
			d->exp--;
			d->man = d->man << 1;
		}
}

t_dcomp			ft_double_struct(double d, int hexa)
{
	t_dcomp			comp;
	unsigned long	*dd;

	dd = (unsigned long*)&d;
	comp.sign = ((*dd & M_SIGN) ? 1 : 0);
	comp.exp = (*dd & M_EXP) >> SHIFT_EXP;
	comp.man = (*dd & M_MAN);
	comp.islong = 0;
	comp.exp10 = 0;
	comp.spe = check_spe(comp);
	if (comp.spe == DS_SUB)
		comp.exp = SUB_EXP;
	else if (comp.spe == DS_ZERO)
		comp.exp = 0;
	else
		comp.exp -= OFFSET_EXP;
	(void)hexa;
	if (comp.spe == DS_SUB)
		redress_man(&comp);
	else if (hexa)
		(comp.man |= M_LAST);
	return (comp);
}
