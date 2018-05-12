/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:54:07 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:55:02 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	interpret_sizes(t_ptenv *e)
{
	if (e->info.conv_wstr)
	{
		e->info.conv_size = (e->info.conv_wstr ?
						ft_wstrlen(e->info.conv_wstr) : SZE_NULLSTR);
		e->info.tot_conv_size = (e->info.precision_val != -1 ?
			ft_min(e->info.precision_val, e->info.conv_size * sizeof(wchar_t))
			: (int)(e->info.conv_size * sizeof(wchar_t)));
		if (!(e->info.conv_str = ft_wstrtostr(e->info.conv_wstr,
							e->info.tot_conv_size, &e->info.tot_conv_size)))
			return (-1);
	}
	else
	{
		e->info.conv_size = SZE_NULLSTR;
		e->info.tot_conv_size = (e->info.precision_val != -1 ?
			ft_min(e->info.precision_val, e->info.conv_size)
			: e->info.conv_size);
	}
	e->info.arg_size = ft_max(e->info.tot_conv_size,
							e->info.field_width_val);
	return (0);
}

static void	assemble_string(t_ptenv *e)
{
	int	offset;

	offset = (e->info.flags & F_NEGATIVE_FIELD ?
				e->info.tot_conv_size : e->info.arg_size);
	ft_memmove(&e->info.arg_str[offset - e->info.tot_conv_size],
				(e->info.conv_str ? e->info.conv_str : NULLSTR),
				e->info.tot_conv_size);
}

int			treat_wstring(t_ptenv *e, va_list args)
{
	int		i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, intmax_t);
	e->info.conv_wstr = va_arg(args, wchar_t*);
	if (interpret_sizes(e) == -1)
		return (-1);
	if (!(e->info.arg_str = ft_strnew_fill(e->info.arg_size,
					(e->info.flags & F_ZERO_PADDING ? '0' : ' '))))
	{
		free(e->info.conv_str);
		return (-1);
	}
	assemble_string(e);
	free(e->info.conv_str);
	e->arg_pos_i++;
	return (0);
}
