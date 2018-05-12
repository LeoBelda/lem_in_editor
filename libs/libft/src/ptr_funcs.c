/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:15:30 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/29 13:51:54 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_p_converter(t_arg_info *inf)
{
	inf->flags |= F_MEMORY | F_ALTERNATE_FORM;
	inf->type = T_INTEGER_BASE;
	inf->base = 16;
	return (0);
}

int	p_n_converter(t_arg_info *inf)
{
	inf->flags |= F_SIGNED;
	inf->type = T_SIZE_TO_PTR;
	return (0);
}
