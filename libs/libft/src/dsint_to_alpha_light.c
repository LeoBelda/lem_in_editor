/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sint_to_alpha_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:29:13 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/04 14:50:19 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define DSINT_CHARNB 18

static void	padded_uitoa(char *str, uintmax_t n)
{
	int	i;

	i = -1;
	while (++i != -1)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		if (!n)
			break ;
	}
	while (++i < DSINT_CHARNB)
		str[i] = '0';
}

void		dsint_to_alpha_light(char *str, t_dsint n)
{
	char			tmp;
	int				i;
	int				j;

	i = 0;
	while (i < (int)n.size &&
			!ft_ismemzero(&n.tab[i], (n.size - i) * sizeof(uintmax_t)))
	{
		padded_uitoa(&str[i * DSINT_CHARNB], n.tab[i]);
		i++;
	}
	j = (i * DSINT_CHARNB);
	i = 0;
	while (--j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
}
