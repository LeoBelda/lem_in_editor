/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:24:49 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/26 11:01:30 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_invalid_flag(t_arg_info *inf)
{
	inf->flags |= F_INVALID;
	inf->type = T_INVALID;
	inf->invalid_char = *inf->fmt_ref;
	return (0);
}

int	p_backslash_zero(t_arg_info *inf)
{
	inf->flags |= F_INVALID;
	inf->type = T_INVALID;
	return (-1);
}
