/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:54:44 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:13:40 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_prefix(t_ptenv *e, char prefix[3])
{
	if (e->info.conv_str[0] == '-')
	{
		ft_strcpy(prefix, "-0x");
		ft_memmove(e->info.conv_str, &e->info.conv_str[1],
									e->info.conv_size - 1);
		e->info.conv_size--;
		return (3);
	}
	else
	{
		if (e->info.flags & F_BLANK_POSITIVE || e->info.flags & F_SIGN_POSITIVE)
		{
			ft_strcpy(prefix, (e->info.flags & F_BLANK_POSITIVE ?
													" 0x" : "+0x"));
			return (3);
		}
		else
		{
			ft_strcpy(prefix, "0x");
			return (2);
		}
	}
}

static void	interpret_sizes(t_ptenv *e)
{
	e->info.conv_size = ft_strlen(e->info.conv_str);
	e->info.pref_size = (ft_strcmp(e->info.conv_str, "nan") ?
		define_prefix(e, e->info.prefix) : 0);
	e->info.tot_conv_size = e->info.conv_size + e->info.pref_size;
	e->info.arg_size = ft_max(e->info.tot_conv_size,
							e->info.field_width_val);
}

static void	assemble_string(t_ptenv *e)
{
	int	offset;

	offset = (e->info.flags & F_NEGATIVE_FIELD ?
				e->info.tot_conv_size : e->info.arg_size);
	ft_memmove(&e->info.arg_str[offset - e->info.conv_size],
			e->info.conv_str, e->info.conv_size);
	ft_memmove(&e->info.arg_str[(e->info.flags & F_ZERO_PADDING ?
			offset - ft_max(e->info.field_width_val, e->info.tot_conv_size)
			: offset - e->info.tot_conv_size)],
			e->info.prefix, e->info.pref_size);
	if (e->info.flags & F_UPPERCASE)
		ft_strtoupper(e->info.arg_str);
}

int			treat_float_hex(t_ptenv *e, va_list args)
{
	int			i;

	i = 0;
	while (++i <= e->info.arg_f)
		va_arg(args, double);
	if (!(e->info.conv_str = (e->info.flags & F_TLONGDOUBLE ?
			ft_dtoa_hex_ev(ft_ldouble_struct(va_arg(args, long double), 1),
				e->info.precision_val, e->info.flags & F_ALTERNATE_FORM) :
			ft_dtoa_hex(ft_double_struct(va_arg(args, double), 1),
				e->info.precision_val, e->info.flags & F_ALTERNATE_FORM))))
		return (-1);
	interpret_sizes(e);
	if (!(e->info.arg_str = ft_strnew_fill(e->info.arg_size,
			e->info.flags & F_ZERO_PADDING &&
				ft_strcmp(e->info.conv_str, "nan") ? '0' : ' ')))
	{
		free(e->info.conv_str);
		return (-1);
	}
	assemble_string(e);
	free(e->info.conv_str);
	e->arg_pos_f++;
	return (0);
}
