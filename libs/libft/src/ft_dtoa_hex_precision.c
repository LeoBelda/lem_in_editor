/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_hex_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:41:00 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/17 10:47:19 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define IND_S 0
#define IND_F 1
#define IND_MAN 3
#define IND_PEXP 48
#define IND_SEXP 49
#define IND_EXP 50

static void	round_man(t_dcomp *d)
{
	int	pow;

	d->man /= 16;
	pow = get_pow(d->man, 16);
	d->man++;
	if (get_pow(d->man, 16) > pow)
	{
		d->exp += 4;
		if (d->man % 16 == 0)
			d->man /= 16;
	}
}

int			ft_dtoa_hex_round(t_dcomp *d, int prec, int pow)
{
	int	val;
	int	mem;

	mem = 0;
	if (prec == -1 || prec >= pow)
		return (prec == -1 ? prec : prec - pow);
	else
		val = pow - prec;
	while (--val && d->man != 0)
	{
		mem = d->man % 2 ? 1 : 0;
		d->man /= 16;
	}
	if (d->man % 16 >= 8 &&
		!(!mem && d->man % 16 == 8))
		round_man(d);
	else
		d->man /= 16;
	return (-prec);
}

char		*ft_dtoa_hex_addprecision(char *buf, int prec)
{
	char	*str;
	size_t	total_size;
	char	*exp_ptr;

	total_size = ft_countnowhitespace(buf) + prec;
	if (!(str = ft_strnew(total_size)))
		return (NULL);
	ft_strcpynowhitespace(str, buf);
	exp_ptr = ft_strrchr(str, 'p');
	ft_memdeplace(&str[total_size - ft_strlen(exp_ptr)],
				exp_ptr, 0, ft_strlen(exp_ptr));
	ft_memset(exp_ptr, '0', prec);
	return (str);
}
