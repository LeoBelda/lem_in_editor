/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:35:25 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/26 16:35:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_x_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED;
	inf->type = T_INTEGER_BASE;
	inf->base = 16;
	return (0);
}

int	p_upx_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED | F_UPPERCASE;
	inf->type = T_INTEGER_BASE;
	inf->base = 16;
	return (0);
}

int	p_o_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED;
	inf->type = T_INTEGER_BASE;
	inf->base = 8;
	return (0);
}

int	p_upo_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED | F_TLONG;
	inf->type = T_INTEGER_BASE;
	inf->base = 8;
	return (0);
}
