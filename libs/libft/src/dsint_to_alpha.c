/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sint_to_alpha_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:29:13 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 12:27:25 by lbelda           ###   ########.fr       */
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

static void	cut_zeroes(char *str)
{
	size_t	len;
	size_t	ind_nb;

	ind_nb = ft_strspn(str, "0");
	len = ft_strlen(&str[ind_nb]);
	ft_bzero(str, &str[ind_nb] - str);
	ft_memdeplace(str, &str[ind_nb], 0, len);
}

char		*dsint_to_alpha(t_dsint n)
{
	char			tmp;
	char			*str;
	int				i;
	int				j;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (n.size * DSINT_CHARNB + 1))))
		return (NULL);
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
	cut_zeroes(str);
	return (str);
}
