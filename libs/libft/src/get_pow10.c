/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pow10_dsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:57:23 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/13 10:57:24 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_pow(intmax_t a, int base)
{
	int	pow;

	pow = 0;
	while (a)
	{
		a /= base;
		pow++;
	}
	return (pow);
}

int	get_pow10_dsint(t_dsint a)
{
	int			pow10;
	uintmax_t	powcomp;

	pow10 = 18 * a.size;
	powcomp = DSINT_MAX;
	while (a.tab[--a.size] == 0 && (int)a.size > 0)
		pow10 -= 18;
	while (powcomp > a.tab[a.size] && (int)a.size >= 0)
	{
		powcomp /= 10;
		pow10--;
	}
	return (pow10);
}
