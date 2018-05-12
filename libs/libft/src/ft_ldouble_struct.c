/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldouble_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:49:14 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/16 13:02:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define M_SIGN 0x0000000000008000
#define M_EXP 0x0000000000007FFF
#define M_MAN 0xFFFFFFFFFFFFFFFF
#define M_LAST 0x8000000000000000

#define DEC_BIT 4
#define SHIFT_INT 60
#define OFFSET_EXP 16383
#define SUB_EXP -16382

static t_dspe	check_spe(t_dcomp d)
{
	if (d.exp == M_EXP)
		return (!d.man || d.man == M_LAST ? DS_INF : DS_NAN);
	else if (!d.exp)
		return (d.man ? DS_SUB : DS_ZERO);
	else
		return (DS_NORMAL);
}

static void		redress_man(t_dcomp *d, int hexa)
{
	int	i;

	i = 0;
	if (hexa)
		while (++i < DEC_BIT)
			d->exp--;
	if (d->man)
		while (!(d->man & M_LAST))
		{
			d->exp--;
			d->man = d->man << 1;
		}
}

t_dcomp			ft_ldouble_struct(long double d, int hexa)
{
	t_dcomp			comp;
	unsigned long	*dd;

	dd = (unsigned long*)&d;
	comp.sign = ((dd[1] & M_SIGN) ? 1 : 0);
	comp.exp = (dd[1] & M_EXP);
	comp.man = (dd[0] & M_MAN);
	comp.spe = check_spe(comp);
	comp.islong = 1;
	comp.exp10 = 0;
	if (comp.spe == DS_SUB)
		comp.exp = SUB_EXP;
	else if (comp.spe == DS_ZERO)
		comp.exp = 0;
	else
		comp.exp -= OFFSET_EXP;
	if (comp.spe != DS_ZERO)
		redress_man(&comp, hexa);
	return (comp);
}
