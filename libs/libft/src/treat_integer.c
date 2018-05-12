/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:46:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/22 13:36:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_prefix(t_ptenv *e, char prefix[2])
{
	if (e->info.conv_str[0] == '-')
	{
		prefix[0] = '-';
		ft_memmove(e->info.conv_str, &e->info.conv_str[1],
					e->info.conv_size - 1);
		e->info.conv_size--;
		return (1);
	}
	else
	{
		if (e->info.flags & F_BLANK_POSITIVE)
		{
			prefix[0] = ' ';
			return (1);
		}
		else if (e->info.flags & F_SIGN_POSITIVE)
		{
			prefix[0] = '+';
			return (1);
		}
		else
			return (0);
	}
}

static void	add_separator(t_ptenv *e, int offset)
{
	int	i;
	int	from;
	int	count;

	i = e->info.conv_size - 1;
	count = 0;
	while (i >= 0)
	{
		from = ft_max(0, i - 2);
		ft_memmove(&e->info.arg_str[offset - e->info.conv_size - count + from],
				&e->info.conv_str[from], i - from + 1);
		if (i - from == 2 && i != 2)
		{
			e->info.arg_str[offset - e->info.conv_size
							- count + from - 1] = ',';
			count++;
		}
		i -= 3;
	}
	e->info.conv_size += count;
}

static void	interpret_sizes(t_ptenv *e)
{
	e->info.conv_size =
		((e->info.precision_val == 0 || e->info.precision_val == 1)
		&& e->info.conv_str[0] == '0' && !(e->info.flags & F_ZERO_PADDING)) ?
		0 : ft_strlen(e->info.conv_str);
	e->info.pref_size = (e->info.flags & F_SIGNED ?
				define_prefix(e, e->info.prefix) : 0);
	if (e->info.flags & F_SEPARATOR)
		e->info.sep_size = ((e->info.conv_size - 1) / 3);
	e->info.tot_conv_size = (e->info.flags & F_ZERO_PADDING ?
		ft_max(e->info.conv_size + e->info.pref_size + e->info.sep_size,
				e->info.precision_val) :
		ft_max(e->info.conv_size + e->info.sep_size,
			e->info.precision_val) + e->info.pref_size);
	e->info.arg_size = ft_max(e->info.tot_conv_size,
							e->info.field_width_val);
}

static void	assemble_string(t_ptenv *e)
{
	int	offset;

	offset = (e->info.flags & F_NEGATIVE_FIELD ?
				e->info.tot_conv_size : e->info.arg_size);
	if (e->info.flags & F_SEPARATOR)
		add_separator(e, offset);
	else
		ft_memmove(&e->info.arg_str[offset - e->info.conv_size],
			e->info.conv_str, e->info.conv_size);
	ft_memset(&e->info.arg_str[offset - e->info.tot_conv_size], '0',
			e->info.tot_conv_size - e->info.conv_size);
	ft_memmove(&e->info.arg_str[offset - e->info.tot_conv_size],
			e->info.prefix, e->info.pref_size);
}

int			treat_integer(t_ptenv *e, va_list args)
{
	int	i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, uintmax_t);
	if (!(e->info.conv_str =
		e->info.flags & F_SIGNED ? ft_itoa(cast_signed_arg(e, args))
								: ft_uitoa(cast_unsigned_arg(e, args))))
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
