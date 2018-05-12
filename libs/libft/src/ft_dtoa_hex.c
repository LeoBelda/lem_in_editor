/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:08:27 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/17 10:49:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define IND_S 0
#define IND_F 1
#define IND_MAN 3
#define IND_PEXP 48
#define IND_SEXP 49
#define IND_EXP 50

static int	sign_and_spe(char *buf, t_dcomp d)
{
	if (d.sign)
		buf[IND_S] = '-';
	buf[IND_SEXP] = ((int)d.exp < 0 ? '-' : '+');
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
	return (0);
}

char		*ft_dtoa_hex(t_dcomp d, int prec, int alter)
{
	char			buf[100];

	(void)alter;
	ft_memset(buf, ' ', 99);
	buf[99] = 0;
	if (sign_and_spe(buf, d))
		return (ft_strnowhitespace(buf));
	while (d.man % 16 == 0 && d.man)
		d.man /= 16;
	prec = ft_dtoa_hex_round(&d, prec, ft_max(get_pow(d.man, 16) - 1, 0));
	ft_itoa_light(&buf[IND_MAN], 16, d.man);
	ft_itoa_light(&buf[IND_EXP], 10, (int)d.exp);
	ft_memmove(&buf[IND_MAN + 2], &buf[IND_MAN + 1],
				ft_strcspn(&buf[IND_MAN + 1], " "));
	buf[IND_PEXP] = 'p';
	buf[IND_MAN + 1] = '.';
	if (d.spe == DS_ZERO)
		buf[IND_MAN] = '0';
	if (prec > 0)
		return (ft_dtoa_hex_addprecision(buf, prec));
	else
	{
		buf[IND_MAN + 1] = (buf[IND_MAN + 2] == ' ' && !alter ? ' ' : '.');
		return (ft_strnowhitespace(buf));
	}
}
