/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:48:35 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/29 15:37:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_b_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED;
	inf->type = T_INTEGER_BASE;
	inf->base = 2;
	return (0);
}

int	p_upb_converter(t_arg_info *inf)
{
	inf->flags |= F_INTEGER | F_UNSIGNED | F_UPPERCASE;
	inf->type = T_INTEGER_BASE;
	inf->base = 2;
	return (0);
}
