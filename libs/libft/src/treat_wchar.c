/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:33:48 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/18 15:54:51 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assemble_string(t_ptenv *e)
{
	int	offset;

	offset = (e->info.flags & F_NEGATIVE_FIELD ?
				e->info.conv_size : e->info.arg_size);
	ft_memmove(&e->info.arg_str[offset - e->info.conv_size],
			&e->info.wchar, e->info.conv_size);
}

int			treat_wchar(t_ptenv *e, va_list args)
{
	int		i;

	i = 0;
	while (++i <= e->info.arg_i)
		va_arg(args, intmax_t);
	if ((e->info.wchar = ft_wctoi((wchar_t)va_arg(args, intmax_t),
							&e->info.conv_size)) == -1)
		return (-1);
	e->info.arg_size = ft_max(e->info.conv_size, e->info.field_width_val);
	if (!(e->info.arg_str = ft_strnew_fill(e->info.arg_size,
					(e->info.flags & F_ZERO_PADDING ? '0' : ' '))))
		return (-1);
	assemble_string(e);
	e->arg_pos_i++;
	return (0);
}
