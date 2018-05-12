/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:46:38 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:52:58 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (i - from == 2)
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
		&& e->info.conv_str[0] == '0') ? 0 : ft_strlen(e->info.conv_str);
	if (e->info.flags & F_SEPARATOR)
		e->info.sep_size = ((e->info.conv_size - 1) / 3);
	e->info.tot_conv_size = (e->info.flags & F_ZERO_PADDING ?
		ft_max(e->info.conv_size + e->info.sep_size,
				e->info.precision_val) :
		ft_max(e->info.conv_size + e->info.sep_size,
			e->info.precision_val));
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
}

int			treat_biguint(t_ptenv *e, va_list args)
{
	int	i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, uintmax_t);
	if (!(e->info.conv_str =
		dsint_to_alpha(*((t_dsint*)va_arg(args, t_dsint*)))))
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
