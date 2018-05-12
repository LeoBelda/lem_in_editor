/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:15:07 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/13 11:59:32 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SINT_LASTRET 0x8000000000000000
#define SINT_FULL 0xffffffffffffffff

void	inc_dsint(t_dsint a)
{
	int	i;

	i = -1;
	while (++i < (int)a.size)
	{
		a.tab[i]++;
		if (a.tab[i] / DSINT_MAX == 0)
			break ;
	}
}

void	add_dsint(t_dsint a, t_dsint b)
{
	int			i;
	uintmax_t	ret;

	i = -1;
	ret = 0;
	while (++i < (int)a.size)
	{
		a.tab[i] += (b.tab[i] + ret);
		ret = a.tab[i] / DSINT_MAX;
		a.tab[i] = a.tab[i] % DSINT_MAX;
	}
}
