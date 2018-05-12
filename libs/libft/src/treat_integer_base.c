/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:46:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:53:32 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_prefix(t_ptenv *e, char prefix[2])
{
	if (e->info.base == 16)
	{
		prefix[0] = '0';
		prefix[1] = 'x';
		return (2);
	}
	else if (e->info.base == 8)
	{
		e->info.conv_size =
			(e->info.precision_val == -1 && e->info.conv_str[0] == '0' ?
			0 : e->info.conv_size);
		e->info.precision_val =
			ft_max(e->info.precision_val, e->info.conv_size + 1);
		return (0);
	}
	else if (e->info.base == 2)
	{
		prefix[0] = '0';
		prefix[1] = 'b';
		return (2);
	}
	else
		return (-1);
}

static void	interpret_sizes(t_ptenv *e)
{
	e->info.conv_size =
		((e->info.precision_val == 0 || e->info.precision_val == 1)
		&& e->info.conv_str[0] == '0') ? 0 : ft_strlen(e->info.conv_str);
	e->info.pref_size =
		(((e->info.flags & F_ALTERNATE_FORM &&
			(e->info.conv_str[0] != '0' || e->info.base == 8)) ||
			e->info.flags & F_MEMORY) ?
				define_prefix(e, e->info.prefix) : 0);
	e->info.tot_conv_size = (e->info.flags & F_ZERO_PADDING ?
		ft_max(e->info.conv_size + e->info.pref_size, e->info.precision_val) :
		ft_max(e->info.conv_size, e->info.precision_val) + e->info.pref_size);
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
	ft_memset(&e->info.arg_str[offset - e->info.tot_conv_size], '0',
			e->info.tot_conv_size - e->info.conv_size);
	ft_memmove(&e->info.arg_str[offset - e->info.tot_conv_size],
			e->info.prefix, e->info.pref_size);
	if (e->info.flags & F_UPPERCASE)
		ft_strtoupper(e->info.arg_str);
}

int			treat_integer_base(t_ptenv *e, va_list args)
{
	int			i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, uintmax_t);
	if (!(e->info.conv_str =
			ft_itoa_bin_oct_hex(cast_unsigned_arg(e, args), e->info.base)))
		return (-1);
	if (e->info.flags & F_ZERO_PADDING)
		e->info.precision_val = (e->info.field_width_val == 0 ?
						1 : e->info.field_width_val);
	interpret_sizes(e);
	if (!(e->info.arg_str = ft_strnew_fill(e->info.arg_size, ' ')))
	{
		free(e->info.conv_str);
		return (-1);
	}
	assemble_string(e);
	free(e->info.conv_str);
	e->arg_pos_i++;
	return (0);
}
