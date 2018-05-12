/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:45:46 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/29 15:46:57 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_invalid(t_ptenv *e, va_list args)
{
	(void)args;
	e->info.arg_size = e->info.field_width_val > 0 ?
						e->info.field_width_val : 1;
	if (!(e->info.conv_str = ft_strnew_fill(e->info.arg_size,
					(e->info.flags & F_ZERO_PADDING ? '0' : ' '))))
		return (-1);
	e->info.conv_str[e->info.flags & F_NEGATIVE_FIELD ?
					0 : e->info.arg_size - 1] = e->info.invalid_char;
	e->info.arg_str = e->info.conv_str;
	return (0);
}
