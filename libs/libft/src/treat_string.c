/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:55:50 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:54:27 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	interpret_sizes(t_ptenv *e)
{
	e->info.conv_size = (e->info.conv_str ?
						ft_strlen(e->info.conv_str) : SZE_NULLSTR);
	e->info.tot_conv_size = (e->info.precision_val != -1 ?
				ft_min(e->info.precision_val, e->info.conv_size)
				: e->info.conv_size);
	e->info.arg_size = ft_max(e->info.tot_conv_size,
							e->info.field_width_val);
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

int			treat_string(t_ptenv *e, va_list args)
{
	int		i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, intmax_t);
	e->info.conv_str = va_arg(args, char*);
	interpret_sizes(e);
	if (!(e->info.arg_str = ft_strnew_fill(e->info.arg_size,
					(e->info.flags & F_ZERO_PADDING ? '0' : ' '))))
		return (-1);
	assemble_string(e);
	e->arg_pos_i++;
	return (0);
}
