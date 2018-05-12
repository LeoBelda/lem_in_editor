/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:17:33 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/26 11:02:50 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_d_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_SIGNED;
	inf->type = T_INTEGER;
	inf->base = 10;
	return (0);
}

int	p_upd_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_SIGNED | F_TLONG;
	inf->type = T_INTEGER;
	inf->base = 10;
	return (0);
}

int	p_i_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_SIGNED;
	inf->type = T_INTEGER;
	inf->base = 10;
	return (0);
}

int	p_u_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED;
	inf->type = T_INTEGER;
	inf->base = 10;
	return (0);
}

int	p_upu_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED | F_TLONG;
	inf->type = T_INTEGER;
	inf->base = 10;
	return (0);
}
