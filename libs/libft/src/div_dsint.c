/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_sin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:04:51 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/04 18:45:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			div_dsint(t_dsint a, uintmax_t val)
{
	uintmax_t		ret;
	uintmax_t		tmpret;

	ret = 0;
	while (a.size--)
	{
		tmpret = ret;
		ret = a.tab[a.size] % val;
		a.tab[a.size] += (tmpret * DSINT_MAX);
		a.tab[a.size] /= val;
	}
}
