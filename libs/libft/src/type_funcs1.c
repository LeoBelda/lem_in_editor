/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:56:47 by lbelda            #+#    #+#             */
/*   Updated: 2018/04/01 15:32:20 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_tshort_flag(t_arg_info *inf)
{
	inf->flags |= (inf->flags & F_TSHORT) ? F_TSHORTSHORT : F_TSHORT;
	return (1);
}

int	p_tlong_flag(t_arg_info *inf)
{
	inf->flags |= ((inf->flags & F_TLONG) ? F_TLONGLONG : F_TLONG)
				| F_WIDE;
	return (1);
}

int	p_tsize_flag(t_arg_info *inf)
{
	inf->flags |= F_TSIZE;
	return (1);
}

int	p_tmax_flag(t_arg_info *inf)
{
	inf->flags |= F_TMAX;
	return (1);
}

int	p_tlongdouble_flag(t_arg_info *inf)
{
	inf->flags |= F_TLONGDOUBLE;
	return (1);
}
