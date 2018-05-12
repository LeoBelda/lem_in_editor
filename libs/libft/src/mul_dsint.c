/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_sin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:04:51 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/04 14:48:50 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mul_dsint(t_dsint a, uintmax_t val)
{
	size_t			i;
	uintmax_t		ret;

	i = 0;
	ret = 0;
	while (i < a.size)
	{
		a.tab[i] = a.tab[i] * val + ret;
		ret = a.tab[i] / DSINT_MAX;
		a.tab[i] = a.tab[i] % DSINT_MAX;
		i++;
	}
}
