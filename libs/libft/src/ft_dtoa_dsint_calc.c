/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_dsint_calc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:15:18 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/17 10:09:14 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define DSINT_SIZE 1000

#define M_MIN 0x0000000000000001
#define M_MAX 0x0008000000000000
#define M_LMAX 0x4000000000000000
#define M_MAXB 52
#define M_LMAXB 63

static void	get_pow10(t_dcomp d, t_dsint pow10)
{
	uintmax_t	mask;
	int			max;

	max = (d.islong ? M_LMAXB : M_MAXB);
	mask = M_MIN;
	while (!(d.man & mask) && !(mask & (d.islong ? M_LMAX : M_MAX)))
	{
		mask = mask << 1;
		max--;
	}
	while (max)
	{
		mul_dsint(pow10, 10);
		max--;
	}
	while (((int)d.exp) < 0)
	{
		mul_dsint(pow10, 10);
		d.exp++;
	}
}

static void	get_fraction(t_dcomp *d, t_dsint pow10, t_dsint fraction)
{
	uintmax_t	mask;
	t_dsint		tmp;
	uintmax_t	tmptab[DSINT_SIZE];
	int			bit;

	mask = (d->islong ? M_LMAX : M_MAX);
	tmp = (t_dsint) {tmptab, fraction.size};
	bit = 1;
	while (mask)
	{
		ft_memcpy(tmp.tab, pow10.tab, fraction.size * sizeof(uintmax_t));
		if (d->man & mask)
		{
			rshift_dsint(tmp, bit);
			add_dsint(fraction, tmp);
		}
		bit++;
		mask = mask >> 1;
	}
	add_dsint(fraction, pow10);
	ft_memcpy(tmp.tab, fraction.tab, fraction.size * sizeof(uintmax_t));
	((int)d->exp > 0 ? lshift_dsint(fraction, d->exp)
					: rshift_dsint(fraction, -((int)d->exp)));
	d->exp10 = get_pow10_dsint(fraction) - get_pow10_dsint(tmp);
}

int			ft_dtoa_dsint_calc(t_dcomp *d, t_dsint *fraction)
{
	t_dsint			pow10;

	if (create_dsint(fraction, DSINT_SIZE))
	{
		if (!create_dsint(&pow10, DSINT_SIZE))
		{
			destroy_dsint(*fraction);
			return (0);
		}
	}
	else
		return (0);
	set_dsint_val(*fraction, 0);
	set_dsint_val(pow10, 1);
	get_pow10(*d, pow10);
	get_fraction(d, pow10, *fraction);
	if (d->spe == DS_ZERO)
		ft_memset(fraction->tab, 0, fraction->size * sizeof(uintmax_t));
	destroy_dsint(pow10);
	return (1);
}
