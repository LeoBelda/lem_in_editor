/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:56:23 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/13 15:13:39 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CONV_BUFF_SIZE 25050
#define IND_S 0
#define IND_F 1
#define IND_ZERO 3
#define IND_MAN 10000
#define IND_EXP CONV_BUFF_SIZE - 50
#define IND_PEXP IND_EXP - 2
#define IND_SEXP IND_EXP - 1
#define IS_G CONV_BUFF_SIZE - 5

#define PO_I 0
#define FR_I 1

static char	*add_precision(char *buf, int *ind, int prec)
{
	char	*str;
	size_t	total_size;
	char	*exp_ptr;

	buf[ind[PO_I]] = '.';
	total_size = ft_countnowhitespace(buf) + prec;
	if (!(str = ft_strnew(total_size)))
		return (NULL);
	ft_strcpynowhitespace(str, buf);
	if (buf[IND_PEXP] == 'e')
	{
		exp_ptr = ft_strrchr(str, 'e');
		ft_memdeplace(&str[total_size - ft_strlen(exp_ptr)],
					exp_ptr, 0, ft_strlen(exp_ptr));
		ft_memset(exp_ptr, '0', prec);
	}
	else
	{
		ft_memrset(&str[--total_size], '0', prec);
	}
	return (str);
}

static char	*remove_trailing_zero(char *buf, int *ind, int alter)
{
	int	i;

	buf[IS_G] = ' ';
	i = IND_PEXP - 1;
	while (buf[i] == ' ' && i != ind[PO_I])
		i--;
	while (buf[i] == '0' && i != ind[PO_I])
	{
		buf[i] = ' ';
		i--;
	}
	buf[ind[PO_I]] = (!alter && buf[ind[FR_I]] == ' ' ? ' ' : '.');
	return (ft_strnowhitespace(buf));
}

static char	*finalize_format(char *buf, int *ind, int prec, int alter)
{
	if (buf[IS_G] == 'g')
		return (remove_trailing_zero(buf, ind, alter));
	if (prec <= 0)
	{
		buf[ind[PO_I]] = (!alter && buf[ind[FR_I]] == ' ' ? ' ' : '.');
		return (ft_strnowhitespace(buf));
	}
	else
		return (add_precision(buf, ind, prec));
}

char		*ft_dtoa_format_e(char *buf, t_dcomp d, int prec, int alter)
{
	size_t	i;
	int		ind[2];

	i = IND_MAN - 1;
	if (buf[IND_MAN] == ' ')
		buf[IND_MAN] = '0';
	while (buf[++i] == '0' && buf[i + 1] != ' ')
		buf[i] = ' ';
	ft_itoa_light(&buf[IND_EXP], 10, d.exp10);
	buf[IND_PEXP] = 'e';
	buf[IND_SEXP] = (d.exp10 >= 0 ? '+' : '-');
	if (ft_strcspn(&buf[IND_EXP], " ") == 1)
	{
		ft_memmove(&buf[IND_EXP + 1], &buf[IND_EXP], 1);
		buf[IND_EXP] = '0';
	}
	buf[IND_F] = buf[i];
	ind[PO_I] = i;
	ind[FR_I] = i + 1;
	return (finalize_format(buf, ind, prec, alter));
}

char		*ft_dtoa_format_f(char *buf, t_dcomp d, int prec, int alter)
{
	size_t	i;
	int		ind[2];

	i = IND_MAN - 1;
	if (buf[IND_MAN] == ' ')
		buf[IND_MAN] = '0';
	while (buf[++i] == '0')
		buf[i] = ' ';
	if (d.exp10 >= 0)
	{
		ft_memdeplace(&buf[IND_MAN - 1], &buf[i], ' ', d.exp10 + 1);
		ind[PO_I] = IND_MAN - 1 + d.exp10 + 1;
		ind[FR_I] = i + d.exp10 + 1;
	}
	else
	{
		buf[IND_F] = '0';
		ind[PO_I] = IND_F + 1;
		ft_memset(&buf[IND_ZERO], '0', ft_max(-d.exp10 - 1 +
					(prec < 0 ? prec : 0), 0));
		ind[FR_I] = buf[IND_ZERO] == '0' ? IND_ZERO : i;
	}
	return (finalize_format(buf, ind, prec, alter));
}
