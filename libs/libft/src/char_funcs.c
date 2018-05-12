/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:47:00 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/28 19:28:22 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_c_converter(t_arg_info *inf)
{
	inf->flags |= F_CHAR;
	inf->type = T_CHAR;
	return (0);
}

int	p_upc_converter(t_arg_info *inf)
{
	inf->flags |= F_CHAR | F_WIDE;
	inf->type = T_WCHAR;
	return (0);
}

int	p_s_converter(t_arg_info *inf)
{
	inf->flags |= F_STRING;
	inf->type = T_STRING;
	return (0);
}

int	p_ups_converter(t_arg_info *inf)
{
	inf->flags |= F_STRING | F_WIDE;
	inf->type = T_WSTRING;
	return (0);
}
