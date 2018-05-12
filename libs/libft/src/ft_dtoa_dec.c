/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:08:27 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/13 15:43:28 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

#define CONV_BUFF_SIZE 25050
#define IND_S 0
#define IND_F 1
#define IND_ZERO 3
#define IND_MAN 10000
#define IND_EXP CONV_BUFF_SIZE - 50
#define IND_PEXP IND_EXP - 2
#define IND_SEXP IND_EXP - 1
#define IS_G CONV_BUFF_SIZE - 5

static int	sign_and_spe(char *buf, t_dcomp d)
{
	if (d.sign)
		buf[IND_S] = '-';
	if (d.spe == DS_NAN)
	{
		ft_strcpy(&buf[IND_S], "nan");
		return (1);
	}
	else if (d.spe == DS_INF)
	{
		ft_strcpy(&buf[IND_F], "inf");
		return (1);
	}
	else if (d.spe == DS_ZERO)
		buf[IND_F] = '0';
	return (0);
}

static char	define_mode(t_dcomp d, t_dconv_mode *mode, int *prec)
{
	if (*mode == DCONV_G)
	{
		*mode = ((d.exp10 >= *prec || d.exp10 < -4) && d.spe != DS_ZERO ?
										DCONV_E : DCONV_F);
		if (*mode == DCONV_E)
			*prec = (*prec == 0 ? 0 : *prec - 1);
		else
			*prec = ft_max(-d.exp10 + *prec - 1, -d.exp10);
		return ('g');
	}
	else
		return (' ');
}

char		*ft_dtoa_dec(t_dcomp d, t_dconv_mode mode, int prec, int alter)
{
	char			buf[CONV_BUFF_SIZE];
	t_dsint			fraction;

	ft_memset(buf, ' ', CONV_BUFF_SIZE - 1);
	buf[CONV_BUFF_SIZE - 1] = 0;
	if (sign_and_spe(buf, d))
		return (ft_strnowhitespace(buf));
	if (!ft_dtoa_dsint_calc(&d, &fraction))
		return (NULL);
	buf[IS_G] = define_mode(d, &mode, &prec);
	prec = set_dsint_precision(fraction, &d.exp10, prec, mode);
	dsint_to_alpha_light(&buf[IND_MAN], fraction);
	destroy_dsint(fraction);
	return (mode == DCONV_E ?
		ft_dtoa_format_e(buf, d, prec, alter)
		: ft_dtoa_format_f(buf, d, prec, alter));
}
