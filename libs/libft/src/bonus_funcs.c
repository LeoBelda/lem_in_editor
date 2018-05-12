/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:17:33 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/17 17:43:32 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_m_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED;
	inf->type = T_BIGUINT;
	inf->base = 10;
	return (0);
}

int	p_y_converter(t_arg_info *inf)
{
	inf->type = T_PIXEL_BUFFER;
	return (0);
}

int	p_upy_converter(t_arg_info *inf)
{
	inf->type = T_WPIXEL_BUFFER;
	return (0);
}
