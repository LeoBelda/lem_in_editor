/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dsint_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:00:11 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/13 14:14:00 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	round_dsint(t_dsint a, t_dconv_mode mode, int *exp10)
{
	int	pow10;

	div_dsint(a, 10);
	pow10 = get_pow10_dsint(a);
	inc_dsint(a);
	if (get_pow10_dsint(a) > pow10)
	{
		(*exp10)++;
		if (a.tab[0] % 10 == 0 && mode != DCONV_F)
			div_dsint(a, 10);
	}
}

static int	truncate_dsint(t_dsint a, int val, t_dconv_mode mode, int *exp10)
{
	int	pow10;
	int	prec;
	int	flag;

	pow10 = get_pow10_dsint(a);
	prec = 0;
	flag = val;
	while (pow10 > val++)
		ft_ismemzero(a.tab, sizeof(uintmax_t) * a.size) ?
			prec++ : div_dsint(a, 10);
	if ((val != flag + 1 || a.tab[0] % 100 >= 50) && a.tab[0] % 10 >= 5)
		round_dsint(a, mode, exp10);
	else
		ft_ismemzero(a.tab, sizeof(uintmax_t) * a.size) ?
			prec++ : div_dsint(a, 10);
	return (prec ? -prec : 0);
}

int			set_dsint_precision(t_dsint a, int *exp10, int prec,
								t_dconv_mode mode)
{
	int	val;
	int	cur_pow10;

	if (ft_ismemzero(a.tab, sizeof(uintmax_t) * a.size))
		return (prec);
	while (a.tab[0] % 10 == 0 &&
			!ft_ismemzero(a.tab, sizeof(uintmax_t) * a.size))
		div_dsint(a, 10);
	cur_pow10 = get_pow10_dsint(a);
	val = (mode == DCONV_E ? 1 + prec : 1 + prec + *exp10);
	if (val <= cur_pow10)
		return (prec = truncate_dsint(a, val, mode, exp10));
	else
		return (val - cur_pow10 - 1);
}
