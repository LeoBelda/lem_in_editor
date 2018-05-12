/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_funcs1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:03:31 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/13 15:07:35 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_f_converter(t_arg_info *inf)
{
	inf->flags |= F_FLOAT;
	inf->type = T_FLOAT_DEC_F;
	if (inf->precision_val == -1)
		inf->precision_val = 6;
	return (0);
}

int	p_upf_converter(t_arg_info *inf)
{
	inf->flags |= F_FLOAT | F_UPPERCASE;
	inf->type = T_FLOAT_DEC_F;
	if (inf->precision_val == -1)
		inf->precision_val = 6;
	return (0);
}

int	p_g_converter(t_arg_info *inf)
{
	inf->flags |= F_FLOAT;
	inf->type = T_FLOAT_DEC_G;
	if (inf->precision_val == -1)
		inf->precision_val = 6;
	return (0);
}

int	p_upg_converter(t_arg_info *inf)
{
	inf->flags |= F_FLOAT | F_UPPERCASE;
	inf->type = T_FLOAT_DEC_G;
	if (inf->precision_val == -1)
		inf->precision_val = 6;
	return (0);
}
